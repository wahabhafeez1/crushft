<?php
/**
 * @file
 * crushftp_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crushftp_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crushftp';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'USERS';
  $view->human_name = 'crushftp';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search ';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'userid' => 'userid',
    'username' => 'username',
    'userPass' => 'userPass',
    'clientName' => 'clientName',
    'createdBy' => 'createdBy',
    'last_login' => 'last_login',
    'emailAddress' => 'emailAddress',
    'account_expire' => 'account_expire',
    'size' => 'size',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
    'expiry' => 'expiry',
  );
  $handler->display->display_options['style_options']['default'] = 'userid';
  $handler->display->display_options['style_options']['info'] = array(
    'userid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'username' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'userPass' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clientName' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'createdBy' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'emailAddress' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'account_expire' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'size' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expiry' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Field: Crushftp: User Id */
  $handler->display->display_options['fields']['userid']['id'] = 'userid';
  $handler->display->display_options['fields']['userid']['table'] = 'USERS';
  $handler->display->display_options['fields']['userid']['field'] = 'userid';
  /* Field: Crushftp: User Name */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'USERS';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  /* Field: Crushftp: Password */
  $handler->display->display_options['fields']['userPass']['id'] = 'userPass';
  $handler->display->display_options['fields']['userPass']['table'] = 'USERS';
  $handler->display->display_options['fields']['userPass']['field'] = 'userPass';
  /* Field: Crushftp: Client Name */
  $handler->display->display_options['fields']['clientName']['id'] = 'clientName';
  $handler->display->display_options['fields']['clientName']['table'] = 'USERS';
  $handler->display->display_options['fields']['clientName']['field'] = 'clientName';
  /* Field: Crushftp: Account created by */
  $handler->display->display_options['fields']['createdBy']['id'] = 'createdBy';
  $handler->display->display_options['fields']['createdBy']['table'] = 'USERS';
  $handler->display->display_options['fields']['createdBy']['field'] = 'createdBy';
  $handler->display->display_options['fields']['createdBy']['label'] = 'PM Assigned';
  /* Field: Crushftp: Last Login */
  $handler->display->display_options['fields']['last_login']['id'] = 'last_login';
  $handler->display->display_options['fields']['last_login']['table'] = 'USERS';
  $handler->display->display_options['fields']['last_login']['field'] = 'last_login';
  $handler->display->display_options['fields']['last_login']['date_format'] = 'custom';
  $handler->display->display_options['fields']['last_login']['custom_date_format'] = 'd M y';
  /* Field: Crushftp: E-mail Address */
  $handler->display->display_options['fields']['emailAddress']['id'] = 'emailAddress';
  $handler->display->display_options['fields']['emailAddress']['table'] = 'USERS';
  $handler->display->display_options['fields']['emailAddress']['field'] = 'emailAddress';
  /* Field: Crushftp: Expire Date */
  $handler->display->display_options['fields']['account_expire']['id'] = 'account_expire';
  $handler->display->display_options['fields']['account_expire']['table'] = 'USERS';
  $handler->display->display_options['fields']['account_expire']['field'] = 'account_expire';
  $handler->display->display_options['fields']['account_expire']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['account_expire']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['account_expire']['element_class'] = '<style type="text/css"> .mydivclassname { 	background-color: #FC0; 	width: 45px; 	height: 20px; 	text-align: center; 	margin: 0p';
  $handler->display->display_options['fields']['account_expire']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['account_expire']['date_format'] = 'custom';
  $handler->display->display_options['fields']['account_expire']['custom_date_format'] = '<font color="red">d M y</font>';
  /* Field: Crushftp: Size of FTP folders */
  $handler->display->display_options['fields']['size']['id'] = 'size';
  $handler->display->display_options['fields']['size']['table'] = 'USERS';
  $handler->display->display_options['fields']['size']['field'] = 'size';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Update';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src="/img/update.png" width="30" height="30">
';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'crushftp/update/[userid]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<img src="/img/bin.png" width="30" height="30">';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'crushftp/delete/[userid]';
  /* Field: Crushftp: about to expire */
  $handler->display->display_options['fields']['expiry']['id'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['table'] = 'USERS';
  $handler->display->display_options['fields']['expiry']['field'] = 'expiry';
  $handler->display->display_options['fields']['expiry']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['expiry']['alter']['text'] = '<img src="/img/expire.png" width="50" height="40">';
  $handler->display->display_options['fields']['expiry']['date_format'] = 'long';
  /* Filter criterion: Crushftp: User Id */
  $handler->display->display_options['filters']['userid']['id'] = 'userid';
  $handler->display->display_options['filters']['userid']['table'] = 'USERS';
  $handler->display->display_options['filters']['userid']['field'] = 'userid';
  $handler->display->display_options['filters']['userid']['group'] = 1;
  $handler->display->display_options['filters']['userid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['userid']['expose']['operator_id'] = 'userid_op';
  $handler->display->display_options['filters']['userid']['expose']['label'] = 'User Id';
  $handler->display->display_options['filters']['userid']['expose']['operator'] = 'userid_op';
  $handler->display->display_options['filters']['userid']['expose']['identifier'] = 'userid';
  $handler->display->display_options['filters']['userid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Crushftp: Client Name */
  $handler->display->display_options['filters']['clientName']['id'] = 'clientName';
  $handler->display->display_options['filters']['clientName']['table'] = 'USERS';
  $handler->display->display_options['filters']['clientName']['field'] = 'clientName';
  $handler->display->display_options['filters']['clientName']['group'] = 1;
  $handler->display->display_options['filters']['clientName']['exposed'] = TRUE;
  $handler->display->display_options['filters']['clientName']['expose']['operator_id'] = 'clientName_op';
  $handler->display->display_options['filters']['clientName']['expose']['label'] = 'Client Name';
  $handler->display->display_options['filters']['clientName']['expose']['operator'] = 'clientName_op';
  $handler->display->display_options['filters']['clientName']['expose']['identifier'] = 'clientName';
  $handler->display->display_options['filters']['clientName']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Crushftp: Account created by */
  $handler->display->display_options['filters']['createdBy']['id'] = 'createdBy';
  $handler->display->display_options['filters']['createdBy']['table'] = 'USERS';
  $handler->display->display_options['filters']['createdBy']['field'] = 'createdBy';
  $handler->display->display_options['filters']['createdBy']['exposed'] = TRUE;
  $handler->display->display_options['filters']['createdBy']['expose']['operator_id'] = 'createdBy_op';
  $handler->display->display_options['filters']['createdBy']['expose']['label'] = 'PM Assigned';
  $handler->display->display_options['filters']['createdBy']['expose']['operator'] = 'createdBy_op';
  $handler->display->display_options['filters']['createdBy']['expose']['identifier'] = 'createdBy';
  $handler->display->display_options['filters']['createdBy']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'crushftp';
  $translatables['crushftp'] = array(
    t('Master'),
    t('more'),
    t('Search '),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('User Id'),
    t('User Name'),
    t('Password'),
    t('Client Name'),
    t('PM Assigned'),
    t('Last Login'),
    t('E-mail Address'),
    t('Expire Date'),
    t('Size of FTP folders'),
    t('Update'),
    t('<img src="/img/update.png" width="30" height="30">
'),
    t('Delete'),
    t('<img src="/img/bin.png" width="30" height="30">'),
    t('about to expire'),
    t('<img src="/img/expire.png" width="50" height="40">'),
    t('Page'),
  );
  $export['crushftp'] = $view;

  return $export;
}
