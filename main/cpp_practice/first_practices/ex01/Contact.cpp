// Welcome to the 80s and their unbelievable technology! Write a program that behaves
// like a crappy awesome phonebook software.
// You have to implement two classes:
// • PhoneBook
// ◦ It has an array of contacts.
// ◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
// replace the oldest one by the new one.
// ◦ Please note that dynamic allocation is forbidden.
// • Contact
// ◦ Stands for a phonebook contact.
// In your code, the phonebook must be instantiated as an instance of the PhoneBook
// class. Same thing for the contacts. Each one of them must be instantiated as an instance
// of the Contact class. You’re free to design the classes as you like but keep in mind that
// anything that will always be used inside a class is private, and that anything that can be
// used outside a class is public.

#include "./Contact.hpp"

string Contact::get_first_name(){
    return first_name;}

string Contact::get_last_name(){
    return last_name;}

string Contact::get_nick_name(){
    return nick_name;}

string Contact::get_phone_num(){
    return phone_num;}

string Contact::get_secret(){
    return secret;}

int Contact::set_first_name(string in){
    first_name = in;
    return 0;}

int Contact::set_last_name(string in){
    last_name = in;
    return 0;}

int Contact::set_nick_name(string in){
    nick_name = in;
    return 0;}

int Contact::set_phone_num(string in){
    phone_num = in;
    return 0;}

int Contact::set_secret(string in){
    secret = in;
    return 0;}
