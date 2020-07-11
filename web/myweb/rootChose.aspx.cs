using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class rootChose : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        YF.JsHelper.Redirect("outUser.aspx");
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        YF.JsHelper.Redirect("outDoctor.aspx");

    }
    protected void Button3_Click(object sender, EventArgs e)
    {

    }
}