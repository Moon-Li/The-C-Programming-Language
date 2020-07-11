using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class index : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            string id = Request.QueryString["id"];
            YF.Mode.User user = YF.BLL.User.getUser(int.Parse(id));
            this.name.Text = user.Name;
            this.rename.Text = user.Rename;
            string sex = "女";
            if (user.Sex == 1)
                sex = "男";
            this.sex.Text = sex;
            this.email.Text = user.Email;
            this.phone.Text = user.Phone;
            this.address.Text = user.Address;
            this.password.Text = "******";
            //this.HF.Value = user.Id.ToString();
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string user_name = this.name.Text;
        string str = "Upnumber.aspx?name=";
        
        YF.Mode.User user = YF.BLL.User.getUserName(user_name);
        string str2 = user.Name;
        str = str.Insert (19,str2);

        YF.JsHelper.Redirect(str);
    }
}