/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_evt_start_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  byte bStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  byte bStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_24;
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x854))(1,param_1,*(code **)(_r_ip_funcs_p + 0x854));
  if (iVar4 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x4c1,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x55);
      (**(code **)(_r_ip_funcs_p + 0x168))(param_1,0,*(code **)(_r_ip_funcs_p + 0x168));
      iVar7 = (uint)bVar1 * 0x5a;
      pcVar6 = *(code **)(_r_modules_funcs_p + 0x1e0);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      (*pcVar6)(*(ushort *)(iVar4 + iVar7) & 0x1f,(uint)bVar1,&bStack_41,&uStack_40);
      if ((bStack_41 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar7);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar7) = uVar2 & 0xff7f | (ushort)bStack_41 << 7;
      if (((byte)uStack_40 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      uVar3 = (ushort)(byte)uStack_40;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar7);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_ip_funcs_p;
      uStack_40 = *(undefined4 *)(_r_ip_funcs_p + 0x148);
      *(ushort *)(iVar5 + iVar7) = uVar2 & 0xffbf | uVar3 << 6;
      uStack_3c = *(undefined4 *)(param_1 + 4);
      uStack_2b = 0;
      uStack_38 = *(undefined4 *)(param_1 + 8);
      uStack_27 = 0;
      uStack_30 = (uint)*(byte *)(param_1 + 0x55);
      uStack_26 = 1;
      uStack_24 = 0;
      uStack_34 = *(undefined4 *)(param_1 + 0x10);
      uStack_2c = *(undefined1 *)(param_1 + 0x16);
      uStack_29 = 0xf;
      uStack_2a = uStack_2c;
      bStack_28 = bVar1;
      (**(code **)(iVar4 + 0x6c8))(&uStack_40,*(code **)(iVar4 + 0x6c8));
      *(undefined1 *)(param_1 + 0x5b) = 1;
      *(undefined1 *)(param_1 + 100) = 0;
    }
                    /* WARNING: Could not recover jumptable at 0x000115b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x854))(0,param_1,*(code **)(_r_ip_funcs_p + 0x854));
    return;
  }
  return;
}

