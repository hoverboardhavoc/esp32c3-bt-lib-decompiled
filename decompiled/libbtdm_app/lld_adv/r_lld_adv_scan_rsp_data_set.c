/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  code *UNRECOVERED_JUMPTABLE;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar3 = *(ushort *)(iVar6 + 0x74) & 0x10;
  uVar2 = param_1 * 9 & 0xff;
  if ((*(ushort *)(iVar6 + 0x74) & 0x10) == 0) {
    uVar4 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
    *(ushort *)(iVar6 + 0x76) = *(ushort *)(iVar6 + 0x76) & 0xf000 | uVar4 & 0xfff;
    if (param_4 != 0) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)((uVar2 + 2 & 0xff) * 0xe + 4 + iVar5);
    }
    iVar5 = _r_ip_funcs_p;
    *(short *)(iVar6 + 0x84) = (short)param_2;
    UNRECOVERED_JUMPTABLE = *(code **)(iVar5 + 0x1ac);
    *(undefined2 *)(iVar6 + 0x80) = param_3;
    (*UNRECOVERED_JUMPTABLE)(*(undefined1 *)(iVar6 + 0x87),UNRECOVERED_JUMPTABLE);
  }
  else {
    iVar6 = (uVar2 + 1 & 0xff) * 0xe;
    uVar3 = 0;
    if (param_4 != 0) {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar5 + iVar6 + 4);
    }
    iVar7 = iVar6 + 2;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar5 + iVar7);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar5 + iVar7) = uVar4 & 0xfff0 | 4;
    iVar5 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
    uVar4 = *(ushort *)(iVar5 + iVar7);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar5 + iVar7) = (ushort)((param_2 + 6U & 0xff) << 8) | uVar4 & 0xff;
    iVar7 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
    iVar5 = _r_plf_funcs_p;
    *(undefined2 *)(iVar7 + iVar6 + 4) = param_3;
    iVar5 = (**(code **)(iVar5 + 0xbc))(0x1400,*(code **)(iVar5 + 0xbc));
    uVar4 = *(ushort *)(iVar5 + iVar6);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar6) = (short)uVar2 * 0xe + 0x1400U | uVar4 & 0x8000;
    iVar5 = (**(code **)(_r_modules_funcs_p + 0x1a0))(2,*(code **)(_r_modules_funcs_p + 0x1a0));
    if (iVar5 != 0) {
      if (2 < _g_bt_plf_log_level) {
        ets_printf("TX PTI [LDC SCANRSP] [EN%d] [%d] \n",*(undefined1 *)(iVar5 + 4),
                   *(undefined1 *)(iVar5 + 5));
      }
      uVar2 = (uint)*(byte *)(iVar5 + 5) << 8;
      if ((uVar2 & 0xf000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x33f,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = iVar6 + 10;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar7 + iVar6);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      UNRECOVERED_JUMPTABLE = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar7 + iVar6) = uVar4 & 0xf0ff | (ushort)uVar2;
      bVar1 = *(byte *)(iVar5 + 4);
      iVar5 = (*UNRECOVERED_JUMPTABLE)(0x1400,UNRECOVERED_JUMPTABLE);
      uVar4 = *(ushort *)(iVar5 + iVar6);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar6) = uVar4 & 0xefff | (ushort)bVar1 << 0xc;
    }
  }
  if ((param_4 != 0) && (uVar3 != 0)) {
    if (param_5 == 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xd8);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0xdc);
    }
                    /* WARNING: Could not recover jumptable at 0x000130c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(uVar3,UNRECOVERED_JUMPTABLE);
    return;
  }
  return;
}

