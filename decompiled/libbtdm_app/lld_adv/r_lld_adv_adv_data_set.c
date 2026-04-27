/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_adv_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_set(int param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  char *pcVar8;
  code *UNRECOVERED_JUMPTABLE;
  ushort uVar9;
  int iVar10;
  
  iVar10 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar9 = *(ushort *)(iVar10 + 0x74) & 0x10;
  uVar4 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar10 + 0x74) & 0x10) == 0) {
    uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar10 + 0x76) = *(ushort *)(iVar10 + 0x76) & 0xf000 | uVar6 & 0xfff;
    if (param_4 != 0) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = *(ushort *)((uVar4 + 1 & 0xff) * 0xe + 4 + iVar5);
    }
    iVar5 = _r_ip_funcs_p;
    *(short *)(iVar10 + 0x82) = (short)param_2;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar5 + 0x1ac);
    *(undefined2 *)(iVar10 + 0x7e) = param_3;
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar10 + 0x87),UNRECOVERED_JUMPTABLE);
    goto _L550;
  }
  iVar5 = uVar4 * 0xe;
  uVar9 = 0;
  if (param_4 != 0) {
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar9 = *(ushort *)(iVar7 + iVar5 + 4);
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar6 = *(ushort *)(iVar7 + iVar5 + 2);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar7 + iVar5 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar6 & 0xff;
  iVar7 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
  *(undefined2 *)(iVar7 + iVar5 + 4) = param_3;
  if ((*(ushort *)(iVar10 + 0x74) & 4) == 0) {
    iVar10 = (**(code **)(_r_modules_funcs_p + 0x1a0))(2,*(code **)(_r_modules_funcs_p + 0x1a0));
    if (iVar10 == 0) goto _L550;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L585;
    }
  }
  else {
    iVar10 = (**(code **)(_r_modules_funcs_p + 0x1a0))(3,*(code **)(_r_modules_funcs_p + 0x1a0));
    if (iVar10 == 0) goto _L550;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar10 + 5);
      uVar2 = *(undefined1 *)(iVar10 + 4);
      pcVar8 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L585:
      ets_printf(pcVar8,uVar2,uVar1);
    }
  }
  uVar4 = (uint)*(byte *)(iVar10 + 5) << 8;
  if ((uVar4 & 0xf000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = iVar5 + 10;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar6 = *(ushort *)(iVar7 + iVar5);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar7 + iVar5) = uVar6 & 0xf0ff | (ushort)uVar4;
  bVar3 = *(byte *)(iVar10 + 4);
  iVar10 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
  uVar6 = *(ushort *)(iVar10 + iVar5);
  iVar10 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar10 + iVar5) = uVar6 & 0xefff | (ushort)bVar3 << 0xc;
_L550:
  if ((param_4 != 0) && (uVar9 != 0)) {
    if (param_5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xd8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xdc);
    }
                    /* WARNING: Could not recover jumptable at 0x00012cf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(uVar9,UNRECOVERED_JUMPTABLE);
    return;
  }
  return;
}

