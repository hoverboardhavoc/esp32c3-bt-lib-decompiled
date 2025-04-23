/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_evt_start_cbk(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  ushort uVar7;
  uint uVar8;
  byte bStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  byte bStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_24;
  
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x844))(1,param_1,*(code **)(_r_ip_funcs_p + 0x844));
  if (iVar3 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x3ab,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x52);
      uVar8 = (uint)bVar1;
      iVar3 = uVar8 * 0x5a;
      uVar2 = *(undefined2 *)(param_1 + 0x4c);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar3 + 0x50 + iVar4) = uVar2;
      (**(code **)(_r_ip_funcs_p + 0x798))(param_1,*(code **)(_r_ip_funcs_p + 0x798));
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar7 = *(ushort *)(iVar4 + iVar3) & 0x1f;
      (**(code **)(_r_ip_funcs_p + 0x304))(uVar8,uVar7,*(code **)(_r_ip_funcs_p + 0x304));
      (**(code **)(_r_ip_funcs_p + 0x2dc))(param_1,*(code **)(_r_ip_funcs_p + 0x2dc));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar7,uVar8,&bStack_41,&uStack_40,*(code **)(_r_modules_funcs_p + 0x1e0));
      if ((bStack_41 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar7 = *(ushort *)(iVar4 + iVar3);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar3) = uVar7 & 0xff7f | (ushort)bStack_41 << 7;
      if (((byte)uStack_40 & 0xfe) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar7 = *(ushort *)(iVar4 + iVar3);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_ip_funcs_p;
      *(ushort *)(iVar5 + iVar3) = uVar7 & 0xffbf | (ushort)(byte)uStack_40 << 6;
      uStack_40 = *(undefined4 *)(iVar4 + 0x2ec);
      uStack_2c = *(undefined1 *)(param_1 + 0x16);
      uStack_3c = *(undefined4 *)(param_1 + 4);
      uStack_2b = 0;
      uStack_34 = *(undefined4 *)(param_1 + 0x10);
      uStack_2a = 0xf00;
      uStack_27 = 0;
      pcVar6 = *(code **)(iVar4 + 0x6c8);
      uStack_38 = 0;
      uStack_26 = 1;
      uStack_24 = 0;
      uStack_30 = uVar8;
      bStack_28 = bVar1;
      (*pcVar6)(&uStack_40,pcVar6);
      *(undefined1 *)(param_1 + 0x53) = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0001135c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x844))(0,param_1,*(code **)(_r_ip_funcs_p + 0x844));
    return;
  }
  return;
}

