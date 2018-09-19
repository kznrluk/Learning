<?php
    $object = [
        'word' => 'Hello, PHP!',
        'today' => date('Y年m月d日'),
        'array_in_array' => array(
            'hello', 'my', 'new', 'programing', 'language', 'PHP'
        ),
        'lambda_in_array' => function(int $value) : int {
            return $value * $value;
        }
    ];

    // 配列へのアクセス
    //echo $object['word'];
    //echo '<br>';

    // 配列なのでアロー演算子は使用できない
    // echo $object->today;

    // 関数なども使える
    //echo $object['lambda_in_array'](16);

    $string = 'wawawa';
    //$number = 234;
    //echo (string)$number ?? 'NOPE';
    echo (string)($number ?? 'aieeee');
    if(isnull($number)){
        echo 'aasusahud';
    } else {
        echo 'kghjkhj';
    }