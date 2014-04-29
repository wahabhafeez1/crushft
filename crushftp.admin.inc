<?php

/**
 * @file
 * The Track Field Changes Admin.
 */

/**
 * Admin crushftp changes.
 * URL 'admin/config/administration/crushftp' page keeps default values for crushftp 
 * These values can be change by administrator
 * These values are same for all crushftp users   
 * Set default values from admin page
 *  - crushftp_database_max_idle_time
 *  - crushftp_max_simultaneous_logins
 *  - crushftp_max_simultaneous_logins
 *  - crushftp_max_logins_per_ip
 *  - crushftp_can_request_files_as_zip
 *  - crushftp_require_encryption
 */

// Form Api is use vertical menu tab
function crushftp_admin_form() {
  $form = array();
  $form['settings'] = array(
    '#type' => 'vertical_tabs',
  );
  //First TAB
  //Database TAB
  $form['database'] = array(
    '#type' => 'fieldset',
    '#title'       => t('Database'),
    '#group'       => 'settings',
  );
  $form['database']['crushftp_database_max_idle_time'] = array(
    '#type' => 'textfield',
    '#title' => t('max Idle Time : (in minutes, 0=no limit)'),
    '#default_value' => variable_get('crushftp_database_max_idle_time', 10),
    '#description' => 'Max idle time starts a timer to disconnect someone anytime they are not transferring a file, or getting a directory listing.',
  );
  $form['database']['crushftp_database_max_login_time'] = array(
    '#type' => 'textfield',
    '#title' => t('max Login Time : (in minutes, 0=no limit)'),
    '#default_value' => variable_get('crushftp_database_max_login_time', 0),
    '#description' => 'Max login time sets a timer to automatically disconnect anyone who has been logged in regardless of what they are doing after so many minutes.',
  );
  $form['database']['crushftp_max_simultaneous_logins'] = array(
    '#type' => 'textfield',
    '#title' => t('max Simultaneous Logins : (-1=disable, 0=no limit)'),
    '#default_value' => variable_get('crushftp_max_simultaneous_logins', 0),
    '#description' => 'Max simultaneous logins controls how many times this username can be logged in at once. Be extremely careful setting this to a restrictive value as clients will have trouble connecting. For instance, web browsers often need at least 8.',
  ); 
  $form['database']['crushftp_max_logins_per_ip'] = array(
    '#type' => 'textfield',
    '#title' => t('Max Logins Per Unique IP : (0=no limit) '),
    '#default_value' => variable_get('crushftp_max_logins_per_ip', 0),
    '#description' => 'Max logins per unique IP lets you control how many logins from each IP are allowed. The anonymous account may be limited to 3 connections from any given IP, but allow 50 people in total to be using the username. This makes sure one person is not using all 50 logins.',  
  );  
  $form['database']['crushftp_logins_ip_auto_kick'] = array(
    '#type' => 'select',
    '#title' => t('Auto kick oldest session if exceeded.'),
    '#options' => array(
      'N' => t('No'),
      'Y' => t('Yes'),
    ),
    '#default_value' => variable_get('crushftp_logins_ip_auto_kick', 'FALSE'),
    '#description' => 'Set this to <em>Yes</em> for Auto kick',
  );
  $form['database']['crushftp_per_account_quota'] = array(
    '#type' => 'textfield',
    '#title' => t('Dir to use for Quota :  (Leave blank, or user "../", be cautious..)'),
    '#default_value' => variable_get('crushftp_per_account_quota', ''),
    '#description' => 'Dir to use for quota lets you configure a parent dir for quota calculations. The purpose of this is to have users who are all    member of a group, and they all share the parent users quota.',  
  );
 $form['database']['crushftp_account_expire_rolling_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Extend expiration if used every x days : '),
    '#default_value' => variable_get('crushftp_account_expire_rolling_days', ''),
    '#description' => 'The extend expiration allows you to keep the account expiration rolling further into the future as long as the user remains active enough. If they login once every 30 days, extend it for 30 more days from the current date.',  
  );
  $form['database']['crushftp_account_expire_delete'] = array(
    '#type' => 'select',
    '#title' => t('Auto delete the account when it get expired.'),
    '#options' => array(
      'N' => t('No'),
      'Y' => t('Yes'),
    ),
    '#default_value' => variable_get('crushftp_account_expire_delete', 'FALSE'),
    '#description' => 'Set this to <em>Yes</em> for Auto delete expire account.',
  );
   $form['database']['crushftp_expire_password_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Days : '),
    '#default_value' => variable_get('crushftp_expire_password_days', 60),
    '#description' => 'Expire password will force the user to change their password every X number of days.',  
  );
  $form['database']['crushftp_ftp_size_100'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Size of FTP Memory for 100% : '),
    '#default_value' => variable_get('crushftp_ftp_size_100', '2 GB'),
    '#description' => 'Please Enter size of FTP Memory <em>NOTE</em> Please enter units(bytes KB MB GB) with size.',  
  );
  $form['database']['crushftp_ftp_size_95'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Size of FTP Memory for 95% : '),
    '#default_value' => variable_get('crushftp_ftp_size_95', '1.9 GB'),
    '#description' => 'Please Enter size of FTP Memory <em>NOTE</em> Please enter units(bytes KB MB GB) with size.',
  );
  $form['database']['crushftp_ftp_size_90'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Size of FTP Memory for 90%  : '),
    '#default_value' => variable_get('crushftp_ftp_size_90', '1.8 GB'),
    '#description' => 'Please Enter size of FTP Memory <em>NOTE</em> Please enter units(bytes KB MB GB) with size.',
  );
  $form['database']['crushftp_ftp_size_80'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter Size of FTP Memory for all accounts 80% : '),
    '#default_value' => variable_get('crushftp_ftp_size_80', '1.6 GB'),
    '#description' => 'Please Enter size of FTP Memory <em>NOTE</em> Please enter units(bytes KB MB GB) with size.',
  );
  //Second TAB
  //Crushftp mail TAB
  $form['mail'] = array(
    '#type' => 'fieldset',
    '#title'       => t('crushftp'),
    '#group'       => 'settings',
  );
  $form['mail']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#default_value' => variable_get('crushftp_mail_from', ''),
  );
  return system_settings_form($form);
}

