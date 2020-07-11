using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class upDoctor : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            string id = Request.QueryString["id"];
            YF.Mode.Doctor user = YF.BLL.User.getDoctor(int.Parse(id));
            this.name.Text = user.Name;
            this.age.Text = user.Age;
            this.job.Text = user.Room;
            this.DropDownList2.Text = user.Room;

            this.HF.Value = user.Id.ToString();
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        YF.Mode.Doctor user = new YF.Mode.Doctor();
        user.Id = int.Parse(this.HF.Value);
        user.Name = this.name.Text;
        user.Age = this.age.Text;
        user.Job = this.job.Text;
        user.Room = this.DropDownList2.Text;

        if (YF.BLL.User.UpdateD(user) == true)//修改成功
        {
            YF.JsHelper.AlertAndRedirect("修改成功！", "outDoctor.aspx");
        }
        else//注册失败
        {
            YF.JsHelper.AlertAndRedirect("修改失败!", "upDoctor.aspx");
        }
    }
    protected void HF_ValueChanged(object sender, EventArgs e)
    {

    }
}