/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined2 *puVar11;
  uint uVar12;
  char cVar13;
  
  if (param_1 == 0) goto _L527;
  iVar7 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
  iVar7 = iVar7 + (uint)*(byte *)(param_1 + 0x8e) * 2;
  if ((*(char *)(iVar7 + 0x3d) == '\0') || (*(char *)(param_1 + 0x46) != *(char *)(iVar7 + 0x3d)))
  goto _L527;
  uVar12 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
  bVar1 = *(byte *)(iVar7 + 0x3c);
  if (0x7ffe < (uVar12 - *(ushort *)(param_1 + 0x44) & 0xffff)) goto _L527;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = (uint)bVar1 * 0xe;
  if (*(short *)(iVar8 + iVar6) < 0) goto _L527;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar3 = *(short *)(iVar6 + 4 + iVar8);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar6 + 2 + iVar8);
  uVar5 = (ushort)*(byte *)(iVar7 + 0x3d);
  if (uVar5 == 1) {
    uVar5 = 10;
_L543:
    cVar13 = '\0';
  }
  else if (uVar5 == 2) {
    uVar5 = 6;
    cVar13 = '\x01';
  }
  else {
    cVar13 = '\x18';
    if (uVar5 != 3) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x5a6,
                 *(code **)(_r_plf_funcs_p + 0xc));
      uVar5 = 0;
      goto _L543;
    }
  }
  if (((sVar3 == 0) || ((uVar4 & 3) != 3)) ||
     (pcVar9 = (char *)(**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc))
     , *pcVar9 != cVar13)) {
    if (0 < _g_bt_plf_log_level) {
      puVar10 = (undefined1 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *puVar10;
      puVar11 = (undefined2 *)
                (**(code **)(_r_plf_funcs_p + 0xbc))
                          (sVar3 + uVar5,*(code **)(_r_plf_funcs_p + 0xbc));
      ets_printf("llcp check: %u %u %u %u %u\n",uVar12,uVar2,*puVar11,
                 *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
    }
    (**(code **)(_r_ip_funcs_p + 0x7d4))
              (*(undefined1 *)(param_1 + 0x8e),*(code **)(_r_ip_funcs_p + 0x7d4));
  }
  else {
    iVar7 = *(ushort *)(param_1 + 0x72) + 9 + uVar12;
    iVar6 = iVar7 * 0x10000;
    puVar10 = (undefined1 *)
              (**(code **)(_r_plf_funcs_p + 0xbc))(sVar3 + uVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar10 = (char)((uint)iVar6 >> 0x10);
    puVar10[1] = (char)((uint)iVar7 >> 8);
    *(short *)(param_1 + 0x44) = (short)((uint)iVar6 >> 0x10);
  }
_L527:
  r_lld_con_evt_start_cbk(param_1);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar7 + 0x19) == '\x02') {
    (**(code **)(_r_ip_funcs_p + 0x9dc))(param_1,*(code **)(_r_ip_funcs_p + 0x9dc));
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

