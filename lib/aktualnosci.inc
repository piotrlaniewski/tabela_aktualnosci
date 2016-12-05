<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function fetchAllNews($connectDB, $sort = "DESC"){//wyswietlanie wszystkich aktualnosci
    $arrayNews = array();
    if($sort == null or ($sort != "ASC" and $sort !="DESC")){//domyślne sortowanie od najnowszej
        $sort = "DESC";//przypisanie do zmiennej sort
    }
    
    $sqlQuery = "SELECT * FROM t_aktualnosci ORDER BY data ".$sort;
    $sqlResult = mysqli_query($connectDB, $sqlQuery);
    $numRows = mysqli_num_rows($sqlResult);
    
    if($numRows > 0){
        while($oneRow = mysqli_fetch_assoc($sqlResult)){
            $arrayNews[] = $oneRow;
            //return $oneRow;
        }
        return $arrayNews;
    }else{
        return 0;//brak aktualności
    }
};
//function stareS($connectDB){
  //  $zapytanie = "SELECT * FROM t_aktualnosci ORDER BY data ASC;";
//};
//function noweS($connectDB){
 //   $zapytanie = "SELECT * FROM t_aktualnosci ORDER BY data DESC;";
//};

function addNew($connectDB){ //dodawanie nowej aktualnosci
    $sqlQuery = "INSERT INTO `t_aktualnosci`(`tytul_aktualnosci`, `naglowek_aktualnosc`, `data`) VALUES ('Nowa aktualnosc','Panno święta, co Jasnej bronisz Częstochowy I w Ostrej świecisz Bramie! Ty, co gród zamkowy Nowogródzki ochraniasz z jego wiernym ludem! Jak mnie dziecko do zdrowia powróciłaś cudem  Gdy od płaczącej matki, pod Twoją opiekęOfiarowany martwą podniosłem powiekę; I zaraz mogłem pieszo, do Twych świątyń progu Iść za wrócone życie podziękować Bogu —) Tak nas powrócisz cudem na Ojczyzny łono!... Tymczasem, przenoś moją duszę utęsknionąDo tych pagórków leśnych, do tych łąk zielonych, Szeroko nad błękitnym Niemnem rozciągnionych; Do tych pól malowanych zbożem rozmaitem, Wyzłacanych pszenicą, posrebrzanych żytem; Gdzie bursztynowy świerzop, gryka jak śnieg biała, Gdzie panieńskim rumieńcem dzięcielina pała, A wszystko przepasane jakby wstęgą, miedzą Zieloną, na niej zrzadka ciche grusze siedzą.',NOW())";
//echo $sqlQuery;    
mysqli_query($connectDB, $sqlQuery);
    
}//koniec funkcji