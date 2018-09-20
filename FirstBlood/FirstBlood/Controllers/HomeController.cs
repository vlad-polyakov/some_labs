using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using FirstBlood.Models;


namespace FirstBlood.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
      public ViewResult Index()
        {
            return View();
        }
        [HttpGet]
      public ViewResult RsvpForm()
        {
            return View();
        }
        [HttpPost]
        public ViewResult RsvpForm(Guests guests)
        {
            if (ModelState.IsValid)
                return View("Thanks", guests);
            else
                return View();
        }
    }
}