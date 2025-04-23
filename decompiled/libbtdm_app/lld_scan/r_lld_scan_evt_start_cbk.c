/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  bool bVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  byte bStack_51;
  undefined4 uStack_50;
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
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x38);
    uVar7 = (uint)bVar1;
    iVar3 = uVar7 * 0x5a;
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar8 = *(ushort *)(iVar4 + iVar3) & 0x1f;
    if (*(char *)(param_1 + 0x3e) != '\x01') {
      if (_lld_scan_sync_env == 0) {
        bVar5 = false;
        uVar6 = 0;
      }
      else {
        bVar5 = *(char *)(_lld_scan_sync_env + 1) != '\0';
        uVar6 = (uint)bVar5;
      }
      *(bool *)(param_1 + 0x44) = bVar5;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar4 + iVar3 + 0x14);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar4 + iVar3 + 0x14) = uVar2 & 0xfff7 | (ushort)(uVar6 << 3);
    }
    (**(code **)(_r_modules_funcs_p + 0x1e0))
              (uVar8,uVar7,&bStack_51,&uStack_50,*(code **)(_r_modules_funcs_p + 0x1e0));
    if ((bStack_51 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x82,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar4 + iVar3) = uVar2 & 0xff7f | (ushort)bStack_51 << 7;
    if (((byte)uStack_50 & 0xfe) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar4 + iVar3);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar3 + iVar4) = uVar2 & 0xffbf | (ushort)(byte)uStack_50 << 6;
    (**(code **)(_r_ip_funcs_p + 0x434))(uVar7,uVar8,*(code **)(_r_ip_funcs_p + 0x434));
    uStack_50 = *(undefined4 *)(_r_ip_funcs_p + 0x3f0);
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
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000133b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0xa74,*(code **)(_r_plf_funcs_p + 8));
  return;
}

