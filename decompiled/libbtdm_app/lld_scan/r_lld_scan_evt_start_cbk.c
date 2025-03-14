/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_evt_start_cbk(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  byte bStack_51;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  if (param_1 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xa5c,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar5 = (uint)bVar1;
    iVar7 = uVar5 * 0x5a;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = _r_plf_funcs_p;
    uVar6 = *(ushort *)(iVar3 + iVar7) & 0x1f;
    if (*(char *)(param_1 + 0x3e) != '\x01') {
      uVar8 = 0;
      if (_lld_scan_sync_env != 0) {
        uVar8 = (uint)(*(char *)(_lld_scan_sync_env + 1) != '\0');
      }
      *(char *)(param_1 + 0x44) = (char)uVar8;
      iVar4 = (**(code **)(iVar4 + 0xbc))(0x400,*(code **)(iVar4 + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar7 + 0x14);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar7 + 0x14) = uVar2 & 0xfff7 | (ushort)(uVar8 << 3);
    }
    (**(code **)(_r_modules_funcs_p + 0x1e0))
              (uVar6,uVar5,&bStack_51,&uStack_50,*(code **)(_r_modules_funcs_p + 0x1e0));
    if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar7);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar7) = uVar2 & 0xff7f | (ushort)((uint)bStack_51 << 7);
    uVar8 = (uStack_50 & 0xff) << 6;
    if ((uVar8 & 0xffffffbf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar7);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar7) = uVar2 & 0xffbf | (ushort)uVar8;
    (**(code **)(_r_ip_funcs_p + 0x434))(uVar5,uVar6,*(code **)(_r_ip_funcs_p + 0x434));
    uStack_50 = *(uint *)(_r_ip_funcs_p + 0x3f0);
    uStack_3b = 0;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_37 = 0;
    uStack_34 = 0;
    uStack_48 = *(undefined4 *)(param_1 + 8);
    uStack_40 = (uint)*(byte *)(param_1 + 0x40);
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    uStack_3a = rwip_priority;
    uStack_39 = 0xf;
    uStack_36 = *(char *)(param_1 + 0x3e) == '\x01';
    bStack_38 = bVar1;
    (**(code **)(_r_ip_funcs_p + 0x6c8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6c8));
    (**(code **)(_r_ip_funcs_p + 0x714))(0,*(code **)(_r_ip_funcs_p + 0x714));
    *(undefined1 *)(param_1 + 0x3c) = 1;
  }
  return;
}

