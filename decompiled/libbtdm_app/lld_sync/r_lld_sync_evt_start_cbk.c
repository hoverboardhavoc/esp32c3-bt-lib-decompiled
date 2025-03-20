/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte bStack_41;
  uint uStack_40;
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
      (**(code **)(_r_plf_funcs_p + 8))("lld_sync.c",0x4c1,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x55);
      (**(code **)(_r_ip_funcs_p + 0x168))(param_1,0,*(code **)(_r_ip_funcs_p + 0x168));
      iVar6 = (uint)bVar1 * 0x5a;
      pcVar3 = *(code **)(_r_modules_funcs_p + 0x1e0);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      (*pcVar3)(*(ushort *)(iVar4 + iVar6) & 0x1f,(uint)bVar1,&bStack_41,&uStack_40);
      if (((uint)bStack_41 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar6);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar6) = uVar2 & 0xff7f | (ushort)((uint)bStack_41 << 7);
      uVar7 = (uStack_40 & 0xff) << 6;
      if ((uVar7 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_sync.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar6);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar4 = _r_ip_funcs_p;
      uStack_40 = *(uint *)(_r_ip_funcs_p + 0x148);
      *(ushort *)(iVar5 + iVar6) = uVar2 & 0xffbf | (ushort)uVar7;
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
    (**(code **)(_r_ip_funcs_p + 0x854))(0,param_1,*(code **)(_r_ip_funcs_p + 0x854));
  }
  return;
}

