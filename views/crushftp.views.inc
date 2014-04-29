<?php

/**
 * @file
 * Provide views data and handlers for field_tracker.module
 */

/**
 * Implements hook_views_handlers().
 */
function crushftp_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'crushftp') . '/views',
    ),
    'handlers' => array(
      'crushftp_user' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function crushftp_views_data() {
  $data = array();
  
  // Need to use USERS as users is already used.
  // Luckily MySQL is not case sensitive.
  $data['USERS']['table']['group'] = t('Crushftp');

  // Advertise this table as a possible base table.
  $data['USERS']['table']['base'] = array(
    'field' => 'users',
    'title' => t('CrushFTP'),
    'help' => t('crushftp'),
    'table' => 'users',
    'alias' => 'users',
    'table_alias' => 'users',
    'database' => 'crushftp',
    'weight' => 10,
  );

  // Id.
  $data['USERS']['userid'] = array(
    'title' => t('User Id'),
    'help' => t('Id for the ftp account'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_numeric'
    ),
  );

  // User name.
  $data['USERS']['username'] = array(
    'title' => t('User Name'),
    'help' => t('The user name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Password.
  $data['USERS']['userPass'] = array(
    'title' => t('Password'),
    'help' => t('The user Password'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_password',
    ),
  );

  // Client name.
  $data['USERS']['clientName'] = array(
    'title' => t('Client Name'),
    'help' => t('Please enter client name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // E-mail address
  $data['USERS']['emailAddress'] = array(
    'title' => t('E-mail Address'),
    'help' => t('Please enter your email address'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // max Idel Time
  $data['USERS']['maxIdleTime'] = array(
    'title' => t('Maximun Idle Time'),
    'help' => t('Maximun Idle Time to lock the user account'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_numeric'
    ),
  );

  // Max Simultaneous Logins.
  $data['USERS']['maxSimultaneousLogins'] = array(
    'title' => t('Maximun Simultaneous Logins'),
    'help' => t('Maximun Simultaneous Logins from user account'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_numeric'
    ),
  );

  // Max Logins PerIP.
  $data['USERS']['maxLoginsPerIP'] = array(
    'title' => t('Maximun Logins per IP'),
    'help' => t('Maximun Logins per IP'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_numeric'
    ),
  );

  // Account expiry.
  $data['USERS']['account_expire'] = array(
    'title' => t('Expire Date'),
    'help' => t('Account Expire Date'),
    'field' => array(
      'handler' => 'crushftp_handler_field_datetime',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'date_views_argument_handler',
    ),
  );
  // about to expire.
  $data['USERS']['expiry'] = array(
    'title' => t('about to expire'),
    'help' => t('about to expire'),
    'field' => array(
      'handler' => 'crushftp_handler_field_expiry',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'date_views_argument_handler',
    ),
  );

    // Last login.
  $data['USERS']['last_login'] = array(
    'title' => t('Last Login'),
    'help' => t('Last login of ftp account'),
    'field' => array(
      'handler' => 'crushftp_handler_field_last_login_datetime',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'date_views_argument_handler',
    ),
  );

  // Request files as Zip.
   $data['USERS']['canRequestFilesAsZip'] = array(
    'title' => t('Request Files as Zip'),
    'help' => t('Select to upload files as Zip'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Require Encryption
  $data['USERS']['requireEncryption'] = array(
    'title' => t('Require encryption'),
    'help' => t('Require encryption to protect data of user account'),
    'field' => array(
      'handler' => 'crushftp_handler_field_require_encrytion',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
/*
  // Created By.
  $data['USERS']['createdBy'] = array(
    'title' => t('Account created by'),
    'help' => t('Enter account creator name'),
    'field' => array(
      'handler' => 'crushftp_handler_field_users',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numaric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );*/

  // Created By.

  $data['USERS']['createdBy'] = array(
    'title' => t('Account created by'),
    'help' => t('Enter account creator name'),
    'field' => array(
      'handler' => 'crushftp_handler_field_users',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'crushftp_handler_filter_users_one',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
 );

    //Size of Ftp folders.
  $data['USERS']['size'] = array(
    'title' => t('Size of FTP folders'),
    'help' => t('Size of Ftp folders'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
  );

  return $data;
}



