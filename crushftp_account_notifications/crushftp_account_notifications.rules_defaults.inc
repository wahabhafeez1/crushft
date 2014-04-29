<?php
/**
 * @file
 * crushftp_account_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function crushftp_account_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_apply_for_leave'] = entity_import('rules_config', '{ "rules_apply_for_leave" : {
      "LABEL" : "Apply for leave",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "mimemail" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "leaves" : "leaves" } } } }
      ],
      "DO" : [
        { "mimemail" : {
            "to" : "wahabhafeez@hotmail.com",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "Applied Leave Status\\r\\n",
            "body" : "you leave is approved\\r\\n[node:field-leave-discription]\\r\\n\\r\\n\\r\\n[node:field-employee-name]\\tEmployee Name\\tField \\u0022field_employee_name\\u0022.\\r\\n[node:field-leave-type-]\\tLeave Type:\\tField \\u0022field_leave_type_\\u0022.\\r\\n[node:field-leave-duration]\\tLeave Duration\\tField \\u0022field_leave_duration\\u0022.\\r\\n[node:field-leave-dates]\\tLeave Dates\\tField \\u0022field_leave_dates\\u0022. The following properties may be appended to the token: value (Start date), value2 (End date), duration (Duration)\\r\\n[node:field-leave-discription]\\tLeave Discription\\tField \\u0022field_leave_discription\\u0022.\\r\\n[node:field-status]\\tStatus\\tField \\u0022field_status\\u0022.\\r\\n[node:field-remarks]\\r\\n\\r\\n\\r\\n[node:field-e-mail-address]\\tE-mail Address"
          }
        }
      ]
    }
  }');
  $items['rules_client_notification_about_accout_is_about_to_expire_'] = entity_import('rules_config', '{ "rules_client_notification_about_accout_is_about_to_expire_" : {
      "LABEL" : "client notification about accout is about to expire ",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "php", "rules", "mimemail" ],
      "USES VARIABLES" : {
        "crushftp" : { "label" : "crushftp", "type" : "crushftp_account" },
        "usr" : { "label" : "usr", "type" : "user" }
      },
      "ACTION SET" : [
        { "mimemail" : {
            "to" : "\\u003C?php echo $crushftp[\\u0027email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "FTP Account is about to expire.",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;Your Account is About to Expire \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that Your Account is about to expire only 7 days left.\\r\\n\\r\\nPlease click either link below to log-in to FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nValid Until: \\u003C?php echo $crushftp[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [usr:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_client_notification_accout_is_expired_'] = entity_import('rules_config', '{ "rules_client_notification_accout_is_expired_" : {
      "LABEL" : "client notification accout is expired ",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "php", "rules", "mimemail" ],
      "USES VARIABLES" : {
        "crushftp" : { "label" : "crushftp", "type" : "crushftp_account" },
        "usr" : { "label" : "usr", "type" : "user" }
      },
      "ACTION SET" : [
        { "mimemail" : {
            "to" : "\\u003C?php echo $crushftp[\\u0027email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "FTP Account is expired.",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;FTP Account is Expired \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that FTP Account is about to expired.\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nValid Until: \\u003C?php echo $crushftp[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [usr:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_crushftp_account_is_about_to_expire'] = entity_import('rules_config', '{ "rules_crushftp_account_is_about_to_expire" : {
      "LABEL" : "Crushftp Account is about to expire",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "php", "rules", "mimemail" ],
      "USES VARIABLES" : {
        "crushftp" : { "label" : "crushftp", "type" : "crushftp_account" },
        "usr" : { "label" : "usr", "type" : "user" }
      },
      "ACTION SET" : [
        { "mimemail" : {
            "to" : "[usr:mail]  \\u003C?php echo $crushftp[\\u0027cc_email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "FTP Account is about to expire.",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;FTP Account is About to Expire \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that Your Account is about to expire only 7 days left.\\r\\n\\r\\nYour files will be deleted, if you wish to archive your file please archive them.\\r\\n\\r\\nPlease click either link below to log-in to FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nValid Until: \\u003C?php echo $crushftp[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [usr:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_crushftp_account_is_expired'] = entity_import('rules_config', '{ "rules_crushftp_account_is_expired" : {
      "LABEL" : "Crushftp Account is expired",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "php", "rules", "mimemail" ],
      "USES VARIABLES" : {
        "crushftp" : { "label" : "crushftp", "type" : "crushftp_account" },
        "usr" : { "label" : "usr", "type" : "user" }
      },
      "ACTION SET" : [
        { "mimemail" : {
            "to" : "[usr:mail]  \\u003C?php echo $crushftp[\\u0027cc_email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "FTP Account is expired.",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;FTP Account is Expired \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that FTP Account is about to expired.\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nValid Until: \\u003C?php echo $crushftp[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [usr:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_crushftp_schedule_account_expiry_client_'] = entity_import('rules_config', '{ "rules_crushftp_schedule_account_expiry_client_" : {
      "LABEL" : "Crushftp schedule account expiry client ",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "crushftp" ],
      "ON" : [ "crushftp_update_expiry_date" ],
      "DO" : []
    }
  }');
  $items['rules_crushftp_schedule_account_expiry_pm_and_recipient_'] = entity_import('rules_config', '{ "rules_crushftp_schedule_account_expiry_pm_and_recipient_" : {
      "LABEL" : "Crushftp schedule account expiry PM and recipient ",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "crushftp" ],
      "ON" : [ "crushftp_update_expiry_date" ],
      "DO" : []
    }
  }');
  $items['rules_crushftp_send_email_for_unlimited_account_to_it'] = entity_import('rules_config', '{ "rules_crushftp_send_email_for_unlimited_account_to_it" : {
      "LABEL" : "crushftp send email for unlimited account to IT",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_send_email_for_unlimited_account" ],
      "DO" : [
        { "mimemail" : {
            "to" : "wahabhafeez@hotmail.com",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "IT \\u0027unlimited\\u0027 account notification",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;IT \\u0027unlimited\\u0027 account notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nPlease set this account to unlimited.\\r\\n\\u003Ctable border =\\u00220px\\u0022\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003EUser Id:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027userid\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EUser Name:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EPassword:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EPM Name:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027PM\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Cbr\\u003E\\r\\n\\r\\nPlease login as a administrator then\\u003Ca href=\\u0022crushftp\\/adminupdate\\/\\u003C? echo $crushftp_account[\\u0027userid\\u0027]; ?\\u003E\\u0022\\u003E click here \\u003C\\/a\\u003E to set this account to unlimited.\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_crushftp_send_email_for_unlimited_account_to_it_after_upda'] = entity_import('rules_config', '{ "rules_crushftp_send_email_for_unlimited_account_to_it_after_upda" : {
      "LABEL" : "crushftp send email for unlimited account to IT after update",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_send_email_for_updated_unlimited_account" ],
      "DO" : [
        { "mimemail" : {
            "to" : "wahabhafeez@hotmail.com",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "IT \\u0027unlimited\\u0027 existing account notification",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;IT \\u0027unlimited\\u0027 existing account notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nPlease set this existing account to unlimited.\\r\\n\\u003Ctable border =\\u00220px\\u0022\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003EUser Id:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027userid\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EUser Name:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EPassword:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003EPM Name:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022150px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027PM\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Cbr\\u003E\\r\\n\\r\\nPlease login as a administrator then\\u003Ca href=\\u0022crushftp\\/adminupdate\\/\\u003C? echo $crushftp_account[\\u0027userid\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u0022\\u003E click here \\u003C\\/a\\u003E to set this account to unlimited.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_e_mail_deleted_crushftp_account_details_to_pm_only'] = entity_import('rules_config', '{ "rules_e_mail_deleted_crushftp_account_details_to_pm_only" : {
      "LABEL" : "E-mail Deleted CrushFTP Account details to PM only",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_delete" ],
      "DO" : [
        { "mimemail" : {
            "to" : "[user:mail]",
            "cc" : "\\u003C?php echo $crushftp_account[\\u0027pmemail\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "Deleted account notification ",
            "body" : "\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003EDeleted account notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n           This email is to confirm the below FTP has been deleted.\\r\\n             User Name: \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n             Password: \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\n             Client Name: \\u003C?php echo $crushftp_account[\\u0027client_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_e_mail_new_crushftp_account_details_to_client_only'] = entity_import('rules_config', '{ "rules_e_mail_new_crushftp_account_details_to_client_only" : {
      "LABEL" : "E-mail new CrushFTP account details to Client only",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_send_email_add_new_user" ],
      "DO" : [
        { "mimemail" : {
            "to" : "\\u003C?php echo $crushftp_account[\\u0027email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "New Account Notification",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;New Account Notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that \\u0027Voice \\u0026 Script International Ltd.\\u0027 has set up an FTP account for you.\\r\\n\\r\\nPlease click either link below to log-in to your FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nExpiry Term: \\u003C?php echo $crushftp_account[\\u0027expiry_term\\u0027]; ?\\u003E :days\\r\\nExpiry date: \\u003C?php echo $crushftp_account[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [user:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_e_mail_new_crushftp_account_details_to_pm_and_recipients'] = entity_import('rules_config', '{ "rules_e_mail_new_crushftp_account_details_to_pm_and_recipients" : {
      "LABEL" : "E-mail new CrushFTP account details to PM and recipients",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_insert" ],
      "DO" : [
        { "mimemail" : {
            "to" : "[user:mail] \\r\\n",
            "cc" : "\\u003C?php echo $crushftp_account[\\u0027cc_email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "New account notification",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;New Account Notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that \\u0027Voice \\u0026 Script International Ltd.\\u0027 has set up an FTP account for you.\\r\\n\\r\\nPlease click either link below to log-in to your FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C? echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C? echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nExpiry Term: \\u003C? echo $crushftp_account[\\u0027expiry_term\\u0027]; ?\\u003E :Days\\r\\nExpiry Date: \\u003C? echo $crushftp_account[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [user:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_e_mail_updated_crushftp_account_details_to_client_only'] = entity_import('rules_config', '{ "rules_e_mail_updated_crushftp_account_details_to_client_only" : {
      "LABEL" : "E-mail updated CrushFTP account details to Client only",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_send_email_account_update" ],
      "DO" : [
        { "mimemail" : {
            "to" : "\\u003C?php echo $crushftp_account[\\u0027email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "Updated account notification",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;Updated Account Notification \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that \\u0027Voice \\u0026 Script International Ltd.\\u0027 has updated FTP account.\\r\\n\\r\\nPlease click either link below to log-in to FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nExpiry Date: \\u003C?php echo $crushftp_account[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [user:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_e_mail_updated_crushftp_account_details_to_pm_and_recipien'] = entity_import('rules_config', '{ "rules_e_mail_updated_crushftp_account_details_to_pm_and_recipien" : {
      "LABEL" : "E-mail updated CrushFTP account details to PM and recipients",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_update" ],
      "DO" : [
        { "mimemail" : {
            "to" : "[user:mail]",
            "cc" : "\\u003C?php echo $crushftp_account[\\u0027cc_email\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "Updated FTP Account",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;Updated FTP Account Details \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis email is to confirm that \\u0027Voice \\u0026 Script International Ltd.\\u0027 has updated FTP account.\\r\\n\\r\\nPlease click either link below to log-in to FTP account.\\r\\n\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp\\r\\nhttp:\\/\\/www.vsi.tv\\/ftp2\\r\\n\\r\\nUser Name: \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\nPassword: \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\r\\nExpiry Date: \\u003C?php echo $crushftp_account[\\u0027expiration_date_email\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\r\\n\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [user:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_ftp_folders'] = entity_import('rules_config', '{ "rules_ftp_folders" : {
      "LABEL" : "ftp folders",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules" ],
      "ON" : [ "cron" ],
      "DO" : [
        { "php_eval" : { "code" : "\\u003C?php\\r\\n   global $user;\\r\\n  $path=\\u0022\\/var\\/www\\/html\\/vsi-intranet\\/ftp\\u0022;\\r\\n  $ar=getDirectorySize($path); \\r\\n  if ($handle = opendir(\\u0027\\/var\\/www\\/html\\/vsi-intranet\\/ftp\\u0027)) {\\r\\n    \\/\\/echo \\u0022Directory handle: $handle\\\\n\\u0022;\\r\\n    \\/\\/echo \\u0022Entries:\\\\n\\u0022;\\r\\n    \\/* This is the correct way to loop over the directory. *\\/\\r\\n    while (false !== ($entry = readdir($handle))) {\\r\\n      \\/\\/echo \\u0022$entry :\\u0022;\\r\\n      $path=\\u0022\\/var\\/www\\/html\\/vsi-intranet\\/ftp\\/$entry\\u0022;\\r\\n     $ar=getDirectorySize($path); \\r\\n      $values  = array(\\u0027size\\u0027 =\\u003E sizeFormat($ar[\\u0027size\\u0027]));\\r\\n        $return_value = NULL;\\r\\n        \\/\\/ store crushftp details in crushftp databse in users table\\r\\n        db_set_active(\\u0027crushftp\\u0027);\\r\\n        try {\\r\\n          $return_value = db_update(\\u0027USERS\\u0027)\\r\\n                          -\\u003Econdition(\\u0027username\\u0027, $entry)\\r\\n                          -\\u003Efields ($values)\\r\\n                          -\\u003Eexecute();\\r\\n        drupal_set_message(t(\\u0027The FTP Folders are updated\\u0027));\\r\\n        watchdog(\\u0027crushftp\\u0027, \\u0027New crushftp user added (@user)\\u0027, array(\\u0027@user\\u0027 =\\u003E $user-\\u003Euid), WATCHDOG_INFO);\\r\\n        }\\r\\n        catch (Exception $e) {\\r\\n        drupal_set_message(t(\\u0027db_insert failed. Message = %message, query= %query\\u0027,\\r\\n        array(\\u0027%message\\u0027 =\\u003E $e-\\u003EgetMessage(), \\u0027%query\\u0027 =\\u003E $e-\\u003Equery_string)), \\u0027error\\u0027);\\r\\n        }  \\r\\n        \\/\\/ Connecting to default drupal database.\\r\\n        db_set_active();\\r\\n    }\\r\\n    closedir($handle);\\r\\n  }\\r\\n\\r\\n\\r\\nfunction getDirectorySize($path) { \\r\\n  $totalsize = 0; \\r\\n  $totalcount = 0; \\r\\n  $dircount = 0; \\r\\n  if ($handle = opendir ($path)) \\r\\n  { \\r\\n    while (false !== ($file = readdir($handle))) \\r\\n    { \\r\\n      $nextpath = $path . \\u0027\\/\\u0027 . $file; \\r\\n      if ($file != \\u0027.\\u0027 \\u0026\\u0026 $file != \\u0027..\\u0027 \\u0026\\u0026 !is_link ($nextpath)) \\r\\n      { \\r\\n        if (is_dir ($nextpath)) \\r\\n        { \\r\\n          $dircount++; \\r\\n          $result = getDirectorySize($nextpath); \\r\\n          $totalsize += $result[\\u0027size\\u0027]; \\r\\n          $totalcount += $result[\\u0027count\\u0027]; \\r\\n          $dircount += $result[\\u0027dircount\\u0027]; \\r\\n        } \\r\\n        elseif (is_file ($nextpath)) \\r\\n        { \\r\\n          $totalsize += filesize ($nextpath); \\r\\n          $totalcount++; \\r\\n        } \\r\\n      } \\r\\n    } \\r\\n  } \\r\\n  closedir ($handle); \\r\\n  $total[\\u0027size\\u0027] = $totalsize; \\r\\n  $total[\\u0027count\\u0027] = $totalcount; \\r\\n  $total[\\u0027dircount\\u0027] = $dircount; \\r\\n  return $total; \\r\\n} \\r\\nfunction sizeFormat($size) { \\r\\n    if($size\\u003C1024) \\r\\n    { \\r\\n        return $size.\\u0022 bytes\\u0022; \\r\\n    } \\r\\n    else if($size\\u003C(1024*1024)) \\r\\n    { \\r\\n        $size=round($size\\/1024,1); \\r\\n        return $size.\\u0022 KB\\u0022; \\r\\n    } \\r\\n    else if($size\\u003C(1024*1024*1024)) \\r\\n    { \\r\\n        $size=round($size\\/(1024*1024),1); \\r\\n        return $size.\\u0022 MB\\u0022; \\r\\n    } \\r\\n    else \\r\\n    { \\r\\n        $size=round($size\\/(1024*1024*1024),1); \\r\\n        return $size.\\u0022 GB\\u0022; \\r\\n    } \\r\\n}\\r\\n?\\u003E" } }
      ]
    }
  }');
  $items['rules_send_email_after_set_account_to_unlimited'] = entity_import('rules_config', '{ "rules_send_email_after_set_account_to_unlimited" : {
      "LABEL" : "Send email after set account to Unlimited",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_admin_site_update" ],
      "DO" : [
        { "mimemail" : {
            "to" : "\\u003C?php echo $crushftp_account[\\u0027pmemail\\u0027]; ?\\u003E",
            "from_name" : "VSI London",
            "from_mail" : "London@vsi.tv",
            "subject" : "IT \\u0027unlimited\\u0027 account response",
            "body" : "\\u003Ctable\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u003Cimg src=\\u0022..\\/img\\/clean_logo.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003Ctd\\u003E\\r\\n\\u003Cimg src=\\u0022..\\/img\\/location_group.png\\u0022\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Ctable bgcolor=\\u0022#ffffff\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n    \\u003Ctd bgcolor=\\u0022#581D74\\u0022 width=\\u00221000px\\u0022 height=\\u002240px\\u0022  \\u003E\\r\\n\\u003Cfont  size=\\u00225px\\u0022 color=\\u0022white\\u0022\\u003E\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;\\u0026nbsp;IT \\u0027unlimited\\u0027 Account Response \\u003C\\/font\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n  \\u003Ctr\\u003E\\r\\n  \\u003Ctd\\u003E\\r\\n    \\u003Ctable border=\\u00221px\\u0022 bordercolor=\\u0022#DCDCDC\\u0022 cellpadding =\\u002230px\\u0022 width=\\u00221000px\\u0022\\u003E\\r\\n      \\u003Ctr\\u003E\\u003Ctd\\u003E\\u003Cfont  size=\\u00223px\\u0022\\u003E\\r\\n\\r\\nThis FTP Account is set to unlimited.\\u003Cbr\\u003E\\r\\n\\r\\n\\u003Ctable border =\\u00220px\\u0022\\u003E\\r\\n\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003EUser Name:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027] . \\u0022\\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003Ctr\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003EPassword:\\u003C\\/td\\u003E\\r\\n\\u003Ctd width = \\u0022100px\\u0022\\u003E \\u003C?php echo $crushftp_account[\\u0027password\\u0027]  .\\u0022 \\\\n\\u0022; ?\\u003E\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Cbr\\u003E\\r\\nFor FTP support please see http:\\/\\/www.vsi.tv\\/helpdesk or e-mail us at [user:mail].\\r\\n\\r\\nThank You.\\r\\n\\r\\nVoice \\u0026 Script International Ltd.\\r\\n         \\u003C\\/font\\u003E\\r\\n     \\u003C\\/td\\u003E\\r\\n  \\u003C\\/tr\\u003E\\r\\n\\u003Ctable\\u003E\\r\\n\\u003C\\/td\\u003E\\r\\n\\u003C\\/tr\\u003E\\r\\n\\u003C\\/table\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_send_email_when_account_is_90_full'] = entity_import('rules_config', '{ "rules_send_email_when_account_is_90_full" : {
      "LABEL" : "Send email when account is 90% full",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "mimemail", "crushftp" ],
      "ON" : [ "crushftp_account_90_%_full_custom_event" ],
      "DO" : [
        { "mimemail" : {
            "to" : "wahabhafeez@hotmail.com",
            "subject" : "account is 90% full",
            "body" : "account is 90% full\\r\\n\\r\\n \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027]; ?\\u003E\\r\\n \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027]; ?\\u003E\\r\\n \\u003C?php echo $crushftp_account[\\u0027user_name\\u0027]; ?\\u003E\\r\\n \\u003C?php echo $crushftp_account[\\u0027pmemail\\u0027]; ?\\u003E"
          }
        }
      ]
    }
  }');
  return $items;
}
