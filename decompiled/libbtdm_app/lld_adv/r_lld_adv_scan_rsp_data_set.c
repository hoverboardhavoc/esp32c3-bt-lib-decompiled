/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_scan_rsp_data_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_scan_rsp_data_set(int param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  code *UNRECOVERED_JUMPTABLE;
  int iVar5;
  ushort uVar6;
  int iVar7;
  
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar6 = *(ushort *)(iVar5 + 0x74) & 0x10;
  uVar3 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar5 + 0x74) & 0x10) == 0) {
    iVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar5 + 0x76) =
         *(ushort *)(iVar5 + 0x76) & 0xf000 | (ushort)((uint)(iVar4 << 0x14) >> 0x14);
    if (param_4 != 0) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar6 = *(ushort *)((uVar3 + 2 & 0xff) * 0xe + 4 + iVar4);
    }
    iVar4 = _r_ip_funcs_p;
    *(short *)(iVar5 + 0x84) = (short)param_2;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar4 + 0x1ac);
    *(undefined2 *)(iVar5 + 0x80) = param_3;
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar5 + 0x87),UNRECOVERED_JUMPTABLE);
  }
  else {
    iVar5 = (uVar3 + 1 & 0xff) * 0xe;
    uVar6 = 0;
    if (param_4 != 0) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar6 = *(ushort *)(iVar4 + iVar5 + 4);
    }
    iVar7 = iVar5 + 2;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar7);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar4 + iVar7) = uVar2 & 0xfff0 | 4;
    iVar4 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
    uVar2 = *(ushort *)(iVar4 + iVar7);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar7) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar2 & 0xff;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_plf_funcs_p;
    *(undefined2 *)(iVar7 + iVar5 + 4) = param_3;
    iVar4 = (**(code **)(iVar4 + 0xbc))(0x1400,*(code **)(iVar4 + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar5);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_modules_funcs_p;
    *(ushort *)(iVar7 + iVar5) = (short)uVar3 * 0xe + 0x1400U | uVar2 & 0x8000;
    iVar4 = (**(code **)(iVar4 + 0x1a0))(2,*(code **)(iVar4 + 0x1a0));
    if (iVar4 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC SCANRSP] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                   *(undefined1 *)(iVar4 + 5));
      }
      bVar1 = *(byte *)(iVar4 + 5);
      if ((bVar1 & 0xf0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = iVar5 + 10;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar7 + iVar5);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar7 + iVar5) = uVar2 & 0xf0ff | (ushort)bVar1 << 8;
      bVar1 = *(byte *)(iVar4 + 4);
      iVar4 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
      uVar2 = *(ushort *)(iVar4 + iVar5);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar5) = uVar2 & 0xefff | (ushort)bVar1 << 0xc;
    }
  }
  if ((param_4 != 0) && (uVar6 != 0)) {
    if (param_5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xd8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xdc);
    }
                    /* WARNING: Could not recover jumptable at 0x00012fca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(uVar6,UNRECOVERED_JUMPTABLE);
    return;
  }
  return;
}

