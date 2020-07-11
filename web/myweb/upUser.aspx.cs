using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class upUser : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            string id = Request.QueryString["id"];
            YF.Mode.User user = YF.BLL.User.getUser(int.Parse(id));
            this.name.Text = user.Name;
            this.rename.Text = user.Rename;
            this.sex.Text = user.Sex.ToString();
            this.email.Text = user.Email;
            this.phone.Text = user.Phone;
            this.address.Text = user.Address;
            this.password.Text = user.Password;
            this.HF.Value = user.Id.ToString();
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        YF.Mode.User user = new YF.Mode.User();
        user.Id = int.Parse(this.HF.Value);
        user.Name = this.name.Text;
        user.Rename = this.rename.Text;
        user.Sex = int.Parse(this.sex.Text);//转整型
        user.Email = this.email.Text;
        user.Phone = this.phone.Text;
        user.Address = this.address.Text;
        user.Password = this.password.Text;

        if (YF.BLL.User.Update(user) == true)//修改成功
        {
            YF.JsHelper.AlertAndRedirect("修改成功！", "outUser.aspx");
        }
        else//注册失败
        {
            YF.JsHelper.AlertAndRedirect("修改失败!", "upUser.aspx");
        }
    }
    protected void HF_ValueChanged(object sender, EventArgs e)
    {

    }
}