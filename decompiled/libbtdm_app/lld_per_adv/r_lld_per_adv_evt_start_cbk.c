/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bStack_41;
  uint uStack_40;
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
  
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x844))(1,param_1,*(code **)(_r_ip_funcs_p + 0x844));
  if (iVar4 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x3c0,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x52);
      uVar6 = (uint)bVar1;
      iVar7 = uVar6 * 0x5a;
      uVar2 = *(undefined2 *)(param_1 + 0x4c);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + 0x50 + iVar4) = uVar2;
      (**(code **)(_r_ip_funcs_p + 0x798))(param_1,*(code **)(_r_ip_funcs_p + 0x798));
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar4 + iVar7) & 0x1f;
      (**(code **)(_r_ip_funcs_p + 0x304))(uVar6,uVar3,*(code **)(_r_ip_funcs_p + 0x304));
      (**(code **)(_r_ip_funcs_p + 0x2dc))(param_1,*(code **)(_r_ip_funcs_p + 0x2dc));
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar3,uVar6,&bStack_41,&uStack_40,*(code **)(_r_modules_funcs_p + 0x1e0));
      if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar4 + iVar7);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar7) = uVar3 & 0xff7f | (ushort)((uint)bStack_41 << 7);
      uVar8 = (uStack_40 & 0xff) << 6;
      if ((uVar8 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar4 + iVar7);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_ip_funcs_p;
      uStack_40 = *(uint *)(_r_ip_funcs_p + 0x2ec);
      *(ushort *)(iVar5 + iVar7) = uVar3 & 0xffbf | (ushort)uVar8;
      uStack_3c = *(undefined4 *)(param_1 + 4);
      uStack_2b = 0;
      uStack_34 = *(undefined4 *)(param_1 + 0x10);
      uStack_27 = 0;
      uStack_2c = *(undefined1 *)(param_1 + 0x16);
      uStack_38 = 0;
      uStack_2a = 0xf00;
      uStack_26 = 1;
      uStack_24 = 0;
      uStack_30 = uVar6;
      bStack_28 = bVar1;
      (**(code **)(iVar4 + 0x6c8))(&uStack_40,*(code **)(iVar4 + 0x6c8));
      *(undefined1 *)(param_1 + 0x53) = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x0001139c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x844))(0,param_1,*(code **)(_r_ip_funcs_p + 0x844));
    return;
  }
  return;
}

