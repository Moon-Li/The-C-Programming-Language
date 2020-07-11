<%@ Page Language="C#" AutoEventWireup="true" CodeFile="outUser.aspx.cs" Inherits="outUser" %>
<%@ Import Namespace="YF.Mode" %>
<%@ Import Namespace="YF.DAL" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:#F2F2F2">
    <form id="form1" runat="server">
    <div style="">
        <br />
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label2" runat="server" Font-Size="20pt" Text="用户信息详情："></asp:Label>
        <br />
        <br />
    <table style="width:800px; text-align:center; margin:auto; border:1px;"" border="1">
        <tr style="text-align:center"><td>编号</td><td>用户名</td><td>昵称</td><td>性别</td><td>邮箱</td><td>电话</td><td>住址</td><td>&nbsp;</td></tr>
        <%
            string id = Request.QueryString["id"];

            if (id != null)
            {
                YF.BLL.User.Del(int.Parse(id));
                YF.JsHelper.AlertAndRedirect("删除成功！", "outUser.aspx");
            }
            
            List<YF.Mode.User> list = YF.BLL.User.listU();
             %>
        <%
            for(int i = 0; i < list.Count; i++)
            {
                string SEX = "女";
                if (list[i].Sex == 1)
                    SEX = "男";
                %>
        <tr><td><%=list[i].Id %></td><td><%=list[i].Name %></td><td><%=list[i].Rename %></td>
            <td><%=SEX %></td><td><%=list[i].Email %></td><td><%=list[i].Phone %></td><td><%=list[i].Address %></td>
            <td><a href="outUser.aspx?id=<%=list[i].Id%>">删除</a> | <a href="upUser.aspx?id=<%=list[i].Id%>">修改</a></td></tr>
                
         <%   }
             %>

    </table>
    </div>
    </form>
</body>
</html>
