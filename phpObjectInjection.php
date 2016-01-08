<?php
class Account {
    private $login;
    private $password;
    public function __construct($login, $password) {
        $this->login=$login;
        $this->password=$password;
    }
    public function __wakeup() {
        system("echo Welcome back " . $this->login );
    }
}

$user1 = new Account('eve','123456');
$user2 = new Account('joe','abcdef');
/*O:7:"Account":2:{s:14:"\x00Account\x00login";s:3:"eve";s:17:"\x00Account\x00password";s:6:"123456";}*/
unserialize(base64_decode($argv[1]));
?>
