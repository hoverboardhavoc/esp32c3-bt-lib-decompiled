/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  
  if (param_1 == 0) goto _L543;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  iVar6 = (uint)*(byte *)(param_1 + 0x8e) * 2 + iVar6;
  if (((*(char *)(iVar6 + 0x3d) == '\0') || (*(char *)(param_1 + 0x46) != *(char *)(iVar6 + 0x3d)))
     || (uVar13 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff,
        0x7ffe < (uVar13 - *(ushort *)(param_1 + 0x44) & 0xffff))) goto _L543;
  bVar1 = *(byte *)(iVar6 + 0x3c);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar12 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar7 + iVar12) < 0) goto _L543;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar3 = *(short *)(iVar7 + iVar12 + 4);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar12 + 2 + iVar7);
  uVar5 = (ushort)*(byte *)(iVar6 + 0x3d);
  if (uVar5 == 1) {
    uVar5 = 10;
_L559:
    cVar11 = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 6;
    cVar11 = '\x01';
  }
  else {
    cVar11 = '\x18';
    if (uVar5 != 3) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x56f,
                 *(code **)(_r_plf_funcs_p + 0xc));
      uVar5 = 0;
      goto _L559;
    }
  }
  if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar8 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc))
     , *pcVar8 != cVar11)) {
    if (0 < _g_bt_plf_log_level) {
      puVar9 = (undefined1 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *puVar9;
      puVar10 = (undefined2 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))
                          (sVar3 + uVar5,*(code **)(_r_plf_funcs_p + 0xbc));
      ets_printf("llcp check: %u %u %u %u %u\n",uVar13,uVar2,*puVar10,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    (**(code **)(_r_ip_funcs_p + 0x7d4))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
  }
  else {
    iVar6 = *(ushort *)(param_1 + 0x72) + 9 + uVar13;
    iVar7 = iVar6 * 0x10000;
    puVar9 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + uVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar9 = (char)((uint)iVar7 >> 0x10);
    puVar9[1] = (char)((uint)iVar6 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar7 >> 0x10);
  }
_L543:
  r_lld_con_evt_start_cbk(param_1);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar6 + 0x19) == '\x02') {
    (**(code **)(_r_ip_funcs_p + 0x9dc))(param_1,*(code **)(_r_ip_funcs_p + 0x9dc));
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010016. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

