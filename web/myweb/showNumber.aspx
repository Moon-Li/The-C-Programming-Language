<%@ Page Language="C#" AutoEventWireup="true" CodeFile="showNumber.aspx.cs" Inherits="showNumber" %>

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
        <asp:Label ID="Label2" runat="server" Font-Size="20pt" Text="当前挂号情况："></asp:Label>
        <br />
        <br />
    <table style="width:800px; text-align:center; margin:auto; border:1px;"" border="1">
        <tr style="text-align:center"><td>姓名</td><td>科室</td><td>病情描述</td></tr>
        <%
            
            List<YF.Mode.Upnum> list = YF.BLL.User.listN();
             %>
        <%
            for(int i = 0; i < list.Count; i++)
            {

                %>
        <tr><td><%=list[i].Name %></td><td><%=list[i].Room %></td><td><%=list[i].Word %></td>
            </tr>
                
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
        <div style="text-align: center">
        <asp:Button ID="Button1" runat="server" Text="就诊完毕请评价！" Font-Size="11pt" Height="32px" Width="128px" />
        </div>
        <br />
    </div>
        
    </form>
</body>
</html>
