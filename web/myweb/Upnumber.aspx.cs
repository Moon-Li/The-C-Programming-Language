using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using YF.BLL;
using YF.DAL;
using YF.Mode;
using YF.MsSqlHelper;

public partial class Upnumber : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            string name = Request.QueryString["name"];
            YF.Mode.User user = YF.BLL.User.getUserName(name);
            this.name.Text = user.Name;
            string sex = "女";
            if (user.Sex == 1)
                sex = "男";
            this.sex.Text = sex;
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        YF.Mode.Upnumber info = new YF.Mode.Upnumber();
        info.Name = this.name.Text;
        info.Room = this.DropDownList2.Text;
        info.Word = this.info.Text;

        if (YF.BLL.User.add(info) == true)//注册成功
        {
            YF.JsHelper.AlertAndRedirect("挂号成功！", "showNumber.aspx");
        }
        else//注册失败
        {
            YF.JsHelper.AlertAndRedirect("挂号失败!", "Upnumber.aspx");
        }
    }
    protected void HF_ValueChanged(object sender, EventArgs e)
    {

    }
}