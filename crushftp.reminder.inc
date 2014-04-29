<?php
/**
 * @file
 */

/*
 * Helper : check input password strength.
 */
// this fucntion is calling from crushftp.module file
require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');

function crushftp_form($crushftp =  NULL) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User Name'),
    '#disabled' => TRUE,
  );
   $form['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
  ); 
     $form['password'] = array(
    '#type' => 'password_confirm',
    '#title' => t(''),
  ); 

  return $form;  
}

function crushftp_reset_password($form, &$form_state, $id) {
  // Connecting to external crushftp database in drupal.
  db_set_active('crushftp');
  // Getting crushftp user information which is stored in crushftp database to update values
  $result = db_select('users', 'u')
            ->condition('userid', $id)
            ->fields('u')
            ->execute()
            ->fetchAssoc();
  // Connecting to default drupal database.
  db_set_active();
  if ($result) {
    $form = crushftp_form();
    $form['userid'] = array(
      '#type' => 'hidden',
      '#default_value' => $result['userid'],
      '#title' => t('ID'),
    );
    $form['name']['#default_value'] = $result['username'];
   // $form['password']['#default_value'] = $result['password'];    
    
 $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update the FTP account'),
    );
    return $form;  
  }
  else {
    form_set_error(t('You can not update crushftp user right now. Please try again later.'), 'error');
  } 
}
function crushftp_reset_password_validate($form, &$form_state) {
  if (!crushftp_valid_pass($form_state['values']['password'])) {
    form_set_error('password', t('That password is too simple.'));
  }
}

function crushftp_reset_password_submit($form, &$form_state) {
  //To get Drupal user details
  global $user;
  $password = $form_state['values']['password'];
  $mdpassword = md5($password);
  $mdpassword1 = 'MD5:' . $mdpassword;
  // connecting to external crushftp database in drupal	
  db_set_active('crushftp');
  $entry = array(
    'password'  => $mdpassword1,
  );
  $return_value = NULL;
  //To get crushftp user Id because Id is uniq and crushftp user account will change values with respect to crushftp user 'id'
  $user_id = array('userid' => $form_state['values']['userid'],); 
  // store edited crushftp details in crushftp databse in users table
  try {
    $return_value = db_update('USERS')
                    ->condition('userid', $user_id)
                    ->fields ($entry)
                    ->execute();
    drupal_set_message(t('Crushftp user Password is reset'));  
    watchdog('crushftp', 'Crushftp user details has been updated (@user)', array('@user' => $user->uid), WATCHDOG_INFO);              
  }
   catch (Exception $e) {
  	drupal_set_message(t('Your can not reset crushftp user password right now. Please try again later.'), 'error');
    drupal_set_message(t('db_update failed. Message = %message, query= %query',
      array('%message' => $e->getMessage(), '%query' => $e->query_string)), 'error');
  }
  // Connecting to default drupal database.
  db_set_active();
}