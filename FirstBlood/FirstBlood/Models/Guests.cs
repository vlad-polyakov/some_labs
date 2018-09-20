using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace FirstBlood.Models
{
    public class Guests
    {
        [Required(ErrorMessage = "Пожалуйста, введите свое имя")]
        public string name { get; set; }
        [Required(ErrorMessage = "Пожалуйста, введите email")]
        [RegularExpression(".+\\@.+\\..+", ErrorMessage = "Вы ввели некорректный email")]
        public string Email { get; set; }
        [Required(ErrorMessage = "Пожалуйста, введите телефон")]
        public string Phone { get; set; }
        [Required(ErrorMessage = "Пожалуйста, укажите, примите ли участие в вечеринке")]
        public bool? Attend { get; set; }
    }
}