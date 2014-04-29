<?php
/**
 * @file
 * Views handlers for crushftp module.
 */
class crushftp_handler_field_require_encrytion extends views_handler_field {
  function render($values) {
    return $values->users_requireencryption;
  }
}
/*
class crushftp_handler_field_user extends views_handler_field {
  function render($values) {
    $uid = (int) $values->users_createdby;
    $user = user_load($uid);
    return $user->name;
  }
}
*/
class crushftp_handler_field_users extends views_handler_field {
  function render($values) {
    $uid = (int) $values->users_createdby;
    $user = user_load($uid);
    return $user->name;
  }
}
class crushftp_handler_field_datetime extends views_handler_field_date {
  function render($values) {
    // Convert the stored datetime text string into a unix timestamp.
    if($values->{$this->field_alias}) {  
      $values->{$this->field_alias} = strToTime($values->{$this->field_alias});
      // Render the date using the normal date handler  
       return parent::render($values);
      }  
    else {
      //return parent::render($values); 
      return t('Never');
    }
  } 
}
//$current_date = Date('d m Y', strtotime("-0 days"));
class crushftp_handler_field_expiry extends views_handler_field_date {
  function render($values) {
    $value = $values->{$this->field_alias} = strToTime($values->{$this->field_alias});    
    // Convert the stored datetime text string into a unix timestamp.
    if($values->{$this->field_alias}) {  
      if($values->{$this->field_alias} < Date(strtotime("+6 days")) ){   
                   
        return t('X');

      }  
      else{
           return t('');
      }
    } 
  } 
}
class crushftp_handler_field_last_login_datetime extends views_handler_field_date {
  function render($values) {
    //Convert the stored datetime text string into a unix timestamp.
    if($values->{$this->field_alias}) {  
      $values->{$this->field_alias} = strToTime($values->{$this->field_alias});
      //Render the date using the normal date handler  
      return parent::render($values);
      }  
    else {
      return t('New Account');
    }
  } 
}
