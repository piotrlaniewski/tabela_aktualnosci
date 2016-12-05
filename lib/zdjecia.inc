<?php
//require 'lib/db_connect1.inc';
//$zdjęcie = '"zdjecia/".$connect[id_aktualnosci]';
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function fetchAllFoto($connectDB1){
    $arrayFoto = array();
    
    $sqlQuery1 = "SELECT * FROM t_galeria;";
    $sqlResult1 = mysqli_query($connectDB1, $sqlQuery1);
    $numRowsF = mysqli_num_rows($sqlResult1);
    
    if($numRowsF > 0){
        while($oneRowF = mysqli_fetch_assoc($sqlResult1)){
            $arrayFoto[] = $oneRowF;
            //return $oneRow;
        }
        return $arrayFoto;
    }else{
        return 0;//brak aktualności
    }
}
function getOnePhoto($connectDB,$id_foto){
    $sqlQuery = "SELECT tytul_foto, nazwa_pliku FROM t_galeria WHERE id_foto=$id_foto";
    $sqlResult = mysqli_query($connectDB, $sqlQuery); //wykonanie zapytania
            
            $numRows = mysqli_num_rows($sqlResult); //zwrotka o ilosć rekordów
    
    if($numRows >0) {//sprawdzamy czy wiecej niż 0
        //$oneRow= mysqli_fetch_row($sqlResult);//pobieranie rekordu jednego zdjecia w postaci tablicy
       // $oneRow= mysqli_fetch_assoc($sqlResult);
        return $oneRow = mysqli_fetch_assoc($sqlResult);// tablica z jednym zdjeciem
    }else{
        return 0;//brak zdjec
    }//koniec sprawdzania
}//koniec funkcji
?>
