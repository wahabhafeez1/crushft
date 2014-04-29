<?php

/**
 * @file
 * Views handlers for crushftp module.
 */

class crushftp_handler_filter_datetime extends views_handler_filter_date {
  function render($values) {
    // Convert the stored datetime text string into a unix timestamp.
    if($values->{$this->field_alias}) {
      $values->{$this->field_alias} = strToTime($values->{$this->field_alias});
      // Render the date using the normal date handler
      return parent::render($values);
    } else {
      return t('Never');
    }
  }
}
class crushftp_handler_filter_users_one extends views_handler_filter_numeric {
  function render($values) {
    $uid = (int) $values->users_createdby;
    $user = user_load($uid);
    return $user->name;
  }
}
