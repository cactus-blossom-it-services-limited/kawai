# Mandela
Development site setup

Add the following lines to the bottom of settings.php to show all errors

```
error_reporting(-1);
$conf['error_level'] = 2;
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
```

In BASH shell:

```
sudo chmod +w sites/default/settings.php
tee -a sites/default/settings.php << END
error_reporting(-1);
$conf['error_level'] = 2;
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
END
sudo chmod -w sites/default/settings.php
```

The debug() function takes any variable, including an object or array (e.g. a form) and 
prints it to the screen.
Par exemple:

```
function mandela_xray_form_alter(&$form, &$form_state, $form_id) {
    debug($form, $form_id, TRUE);
}
```
Put any output generating function or variable inside debug function as the first parameter.
Optionally follow it with a label to keep track of multiple uses of debug().
Par exemple, to print the contents of the $user variable:
```
debug($user, 'User object');
```
(In most places this will be the currently logged-in user).

If unsure whether code is being run at all put this line in your code
```
exit('Let me know it works!');
```

## The Drupal 7 Forms API
  Introduced by Drupal 7, the output of a default #type 'markup' form element
  must be given in a #markup property
