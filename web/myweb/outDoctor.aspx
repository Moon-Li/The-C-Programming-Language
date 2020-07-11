<%@ Page Language="C#" AutoEventWireup="true" CodeFile="outDoctor.aspx.cs" Inherits="outDoctor" %>

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
        <asp:Label ID="Label2" runat="server" Font-Size="20pt" Text="医生信息详情："></asp:Label>
        <br />
        <br />
    <table style="width:800px; text-align:center; margin:auto; border:1px;"" border="1">
        <tr style="text-align:center"><td>编号</td><td>姓名</td><td>年龄</td><td>职位</td><td>科室</td><td>&nbsp;</td></tr>
        <%
            string id = Request.QueryString["id"];

            if (id != null)
            {
                YF.BLL.User.DelDoc(int.Parse(id));
                YF.JsHelper.AlertAndRedirect("删除成功！", "outDoctor.aspx");
            }
            
            List<YF.Mode.Doctor> list = YF.BLL.User.listD();
             %>
        <%
            for(int i = 0; i < list.Count; i++)
            {

                %>
        <tr><td><%=list[i].Id %></td><td><%=list[i].Name %></td><td><%=list[i].Age %></td>
            <td><%=list[i].Job %></td><td><%=list[i].Room %></td>
            <td><a href="outDoctor.aspx?id=<%=list[i].Id%>">删除</a> | <a href="upDoctor.aspx?id=<%=list[i].Id%>">修改</a></td></tr>
                
         <%   }
             %>

    </table>
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    </div>
        <p style="margin:auto;text-align:center">
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="Button1" runat="server" style="margin-bottom: 0px" Text="添加新成员" Height="31px" Width="108px" />
        </p>
    </form>
</body>
</html>
