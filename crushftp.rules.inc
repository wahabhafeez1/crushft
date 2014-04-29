<?php
/**
 * @file rules integration for the crushftp module
 */


/**
 * Implements hook_rules_event_info().
 */
function crushftp_rules_event_info() {
  return array(
    'crushftp_insert' => array(
      'label' => t('After adding a new crushftp account email details'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_update' => array(
      'label' => t('After updating an existing crushftp account email details'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_delete' => array(
      'label' => t('After a crushftp account has been deleted email to PM only'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_send_email_add_new_user' => array(
      'label' => t('After adding a new crushftp account email details to client only'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_send_email_account_update' => array(
      'label' => t('After updating an existing crushftp account email details to client only'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
   'crushftp_send_email_for_unlimited_account' => array(
      'label' => t('crushftp send email for unlimited Account'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_send_email_for_updated_unlimited_account' => array(
      'label' => t('crushftp send email for updated set unlimited Account'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_update_expiry_date' => array(
      'label' => t('crushftp schedule update account expiry'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
   'crushftp_admin_site_update' => array(
      'label' => t('crushftp send email from admin after set account to unlimited'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
    'crushftp_account_90_%_full_custom_event' => array(
      'label' => t('crushftp account 90% full custom event'),
      'group' => t('CrushFTP'),
      'variables' => array(
        'user' => array('type' => 'user', 'label' => t('current user')),
        'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
      ),
    ),
  );
}


/**
 * Implements hook_rules_data_info().
 */
function crushftp_rules_data_info() {
  return array(
    'crushftp_account' => array(
      'label' => t('crushFTP Account'),
      'wrap' => TRUE,
      'property info' => _crushftp_rules_data_info_crushftp_account_info(),
      'group' => t('CrushFTP'),
    ),
  );
}


/**
* Defines crushftp entity.
*/
function _crushftp_rules_data_info_crushftp_account_info() {
  return array(
    'user_name' => array(
      'type' => 'text',
      'label' => t('CrushFTP account username'),
    ),
    'password' => array(
      'type' => 'text',
      'label' => t('CrushFTP account password'),
    ),
    'expiration_date' => array(
      'type' => 'date',
      'label' => t('CrushFTP expiration date'),
    ),
    'email' => array(
      'type' => 'text',
      'label' => t('CrushFTP account email'),
    ),
    'client_name' => array(
      'type' => 'text',
      'label' => t('CrushFTP account client name'),
    ),
    'cc_email' => array(
      'type' => 'text',
      'label' => t('cc email'),
    ),
    'expiration_date_email' => array(
      'type' => 'date',
      'label' => t('expiration date email'),
    ),
    'pmemail' => array(
      'type' => 'text',
      'label' => t('PM E-mail address'),
    ),
    'userid' => array(
      'type' => 'text',
      'label' => t('FTP User id'),
    ),
    'PM' => array(
      'type' => 'text',
      'label' => t('Name of PM'),
    ),
    'expiry_term' => array(
      'type' => 'text',
      'label' => t('Duration of expiry days'),
    ),
    'ftp_size' => array(
      'type' => 'text',
      'label' => t('Size of ftp memory'),
    ), 
      
  );
}
/**
 * ACTION for carusftp when account is 100% full
 * @return type
*/
function crushftp_rules_action_info() {
  return array(
      'crushftp_account_is_100_percent_full_custom_action' => array(
      'label' => t('CrushFTP account is 100 % full'),
      'group' => t('CrushFTP'),
      'variables' => array(
          'user' => array('type' => 'user', 'label' => t('current user')),
          'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
        ),
      ),
      'crushftp_account_is_95_percent_full_custom_action' => array(
      'label' => t('CrushFTP account is 95 % full'),
      'group' => t('CrushFTP'),
      'variables' => array(
          'user' => array('type' => 'user', 'label' => t('current user')),
          'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
        ),
      ),
      'crushftp_account_is_90_percent_full_custom_action' => array(
      'label' => t('CrushFTP account is 90 % full'),
      'group' => t('CrushFTP'),
      'variables' => array(
          'user' => array('type' => 'user', 'label' => t('current user')),
          'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
        ),
      ),
      'crushftp_account_is_80_percent_full_custom_action' => array(
      'label' => t('CrushFTP account is 80 % full'),
      'group' => t('CrushFTP'),
      'variables' => array(
          'user' => array('type' => 'user', 'label' => t('current user')),
          'crushftp_account' => array('type' => 'crushftp_account', 'label' => t('crushftp_account')),
        ),
      ),
  );
}



// call in crushftp_rules_action_info()
function crushftp_account_is_100_percent_full_custom_action() {
  global $user;
  // Connecting to external crushftp database in drupal. to send deleted account details to PM by using Rules module
  $id =170;
  while($id <= 1000){
  db_set_active('crushftp');
    $result = db_select('USERS', 'u')
              ->condition('userid',$id)
              ->condition('size',variable_get('crushftp_ftp_size_100', '2 GB'),'>=')
              ->fields('u')
              ->execute()
              ->fetchAssoc();
    $entry = array(
      'userid' => $result['userid'],
      'user_name' => $result['username'],
      'email' => $result['emailAddress'],
      'size' => $result['size'],
      'pmemail' => $result['createdEmail'],
    );
    if ($entry) {
       // Rules interaction.
       drupal_set_message(t('One ftp account found 100% full'));
       $to      =  $entry['pmemail'];
       $subject = 'FTP Account memory is 100% full';
       $message = 'Hi PM' . "\r\n" . "\n" . 'The Following user has been reached to his FTP memory limit. 100% full' . "\n" 
         . 'User Id: ' . $entry['userid'] . "\n"
         . 'User Name: ' .  $entry['user_name'] . "\n" . "\n" . "\n"
         . 'VSI London';
       $headers = 'From: FTP VSI London';

       mail($to, $subject, $message, $headers);
     }
    else {
      return FALSE;
       drupal_set_message(t('No account is found'));
    } 
    db_set_active();  
    $id++;
  }
}
function crushftp_account_is_95_percent_full_custom_action() {
  global $user;
  // Connecting to external crushftp database in drupal. to send deleted account details to PM by using Rules module
  $id =170;
  while($id <= 1000){
  db_set_active('crushftp');
    $result = db_select('USERS', 'u')
              ->condition('userid',$id)
              ->condition('size',variable_get('crushftp_ftp_size_95', '1.9 GB'),'>=')
              ->fields('u')
              ->execute()
              ->fetchAssoc();
    $entry = array(
      'userid' => $result['userid'],
      'user_name' => $result['username'],
      'email' => $result['emailAddress'],
      'size' => $result['size'],
      'pmemail' => $result['createdEmail'],
    );
    if ($entry) {
       // Rules interaction.
       drupal_set_message(t('One ftp account found 95% full'));
       $to      =  $entry['pmemail'];
       $subject = 'FTP Account memory is 95% full';
       $message = 'Hi PM' . "\r\n" . "\n" . 'The Following user has been reached to his FTP memory 95% full.' . "\n"
         . 'User Id: ' . $entry['userid'] . "\n"
         . 'User Name: ' .  $entry['user_name'] . "\n" . "\n" . "\n"
         . 'VSI London';
       $headers = 'From: FTP VSI London';

       mail($to, $subject, $message, $headers);
     }
    else {
      return FALSE;
       drupal_set_message(t('No account is found'));
    }
    db_set_active();
    $id++;
  }
}
function crushftp_account_is_90_percent_full_custom_action() {
  global $user;
  // Connecting to external crushftp database in drupal. to send deleted account details to PM by using Rules module
  $id =170;
  while($id <= 1000){
  db_set_active('crushftp');
    $result = db_select('USERS', 'u')
              ->condition('userid',$id)
              ->condition('size',variable_get('crushftp_ftp_size_90', '1.8 GB'),'>=')
              ->fields('u')
              ->execute()
              ->fetchAssoc();
    $entry = array(
      'userid' => $result['userid'],
      'user_name' => $result['username'],
      'email' => $result['emailAddress'],
      'size' => $result['size'],
      'pmemail' => $result['createdEmail'],
    );
    if ($entry) {
       // Rules interaction.
       drupal_set_message(t('One ftp account found 90% full'));
       $to      =  $entry['pmemail'];
       $subject = 'FTP Account memory is 90% full';
       $message = 'Hi PM' . "\r\n" . "\n" . 'The Following user has been reached to his FTP memory 90% full.' . "\n"
         . 'User Id: ' . $entry['userid'] . "\n"
         . 'User Name: ' .  $entry['user_name'] . "\n" . "\n" . "\n"
         . 'VSI London';
       $headers = 'From: FTP VSI London';

       mail($to, $subject, $message, $headers);
     }
    else {
      return FALSE;
       drupal_set_message(t('No account is found'));
    }
    db_set_active();
    $id++;
  }
}
function crushftp_account_is_80_percent_full_custom_action() {
  global $user;
  // Connecting to external crushftp database in drupal. to send deleted account details to PM by using Rules module
  $id =170;
  while($id <= 1000){
  db_set_active('crushftp');
    $result = db_select('USERS', 'u')
              ->condition('userid',$id)
            ->condition('size',variable_get('crushftp_ftp_size_80', '1.6 GB'),'>=')
              ->fields('u')
              ->execute()
              ->fetchAssoc();
    $entry = array(
      'userid' => $result['userid'],
      'user_name' => $result['username'],
      'email' => $result['emailAddress'],
      'size' => $result['size'],
      'pmemail' => $result['createdEmail'],
    );
    if ($entry) {
       // Rules interaction.
       drupal_set_message(t('One ftp account found 80% full'));
       $to      =  $entry['pmemail'];
       $subject = 'FTP Account memory is 80% full';
       $message = 'Hi PM' . "\r\n" . "\n" . 'The Fllowing user has been reached to his FTP memory 80% full.' . "\n"
         . 'User Id: ' . $entry['userid'] . "\n"
         . 'User Name: ' .  $entry['user_name'] . "\n" . "\n" . "\n"
         . 'VSI London';
       $headers = 'From: FTP VSI London';

       mail($to, $subject, $message, $headers);
     }
    else {
      return FALSE;
       drupal_set_message(t('No account is found'));
    }
    db_set_active();
    $id++;
  }
}

