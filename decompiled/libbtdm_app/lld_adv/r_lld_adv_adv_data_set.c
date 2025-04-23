/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  code *UNRECOVERED_JUMPTABLE;
  ushort uVar10;
  int iVar11;
  
  iVar11 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar10 = *(ushort *)(iVar11 + 0x74) & 0x10;
  uVar5 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar11 + 0x74) & 0x10) == 0) {
    iVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar11 + 0x76) =
         *(ushort *)(iVar11 + 0x76) & 0xf000 | (ushort)((uint)(iVar6 << 0x14) >> 0x14);
    if (param_4 != 0) {
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar10 = *(ushort *)((uVar5 + 1 & 0xff) * 0xe + 4 + iVar6);
    }
    iVar6 = _r_ip_funcs_p;
    *(short *)(iVar11 + 0x82) = (short)param_2;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar6 + 0x1ac);
    *(undefined2 *)(iVar11 + 0x7e) = param_3;
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar11 + 0x87),UNRECOVERED_JUMPTABLE);
    goto _L498;
  }
  iVar6 = uVar5 * 0xe;
  uVar10 = 0;
  if (param_4 != 0) {
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar10 = *(ushort *)(iVar7 + iVar6 + 4);
  }
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar7 + iVar6 + 2);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + iVar6 + 2) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar4 & 0xff;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar7 = _r_modules_funcs_p;
  *(undefined2 *)(iVar8 + iVar6 + 4) = param_3;
  if ((*(ushort *)(iVar11 + 0x74) & 4) == 0) {
    iVar11 = (**(code **)(iVar7 + 0x1a0))(2);
    if (iVar11 == 0) goto _L498;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar11 + 5);
      uVar2 = *(undefined1 *)(iVar11 + 4);
      pcVar9 = "TX PTI [LDC ADV] [EN%d] [%d] \n";
      goto _L531;
    }
  }
  else {
    iVar11 = (**(code **)(iVar7 + 0x1a0))(3);
    if (iVar11 == 0) goto _L498;
    if (2 < _g_bt_plf_log_level) {
      uVar1 = *(undefined1 *)(iVar11 + 5);
      uVar2 = *(undefined1 *)(iVar11 + 4);
      pcVar9 = "TX PTI [HDC ADV] [EN%d] [%d] \n";
_L531:
      ets_printf(pcVar9,uVar2,uVar1);
    }
  }
  bVar3 = *(byte *)(iVar11 + 5);
  if ((bVar3 & 0xf0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = iVar6 + 10;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar7 + iVar6);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar7 + iVar6) = uVar4 & 0xf0ff | (ushort)bVar3 << 8;
  bVar3 = *(byte *)(iVar11 + 4);
  iVar11 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
  uVar4 = *(ushort *)(iVar11 + iVar6);
  iVar11 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar11 + iVar6) = uVar4 & 0xefff | (ushort)bVar3 << 0xc;
_L498:
  if ((param_4 != 0) && (uVar10 != 0)) {
    if (param_5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xd8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xdc);
    }
                    /* WARNING: Could not recover jumptable at 0x00012bfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(uVar10,UNRECOVERED_JUMPTABLE);
    return;
  }
  return;
}

