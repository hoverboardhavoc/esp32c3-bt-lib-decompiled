/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_sched(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  
  iVar4 = *(int *)(_lld_scan_env + param_1 * 4);
  bVar1 = *(byte *)(iVar4 + 0x38);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x7fc))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7fc));
  if (iVar5 != 0) {
    return;
  }
  if (*(char *)(iVar4 + 0x3e) == '\x01') {
    (**(code **)(_r_ip_funcs_p + 0x718))(*(code **)(_r_ip_funcs_p + 0x718));
    *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0x48);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0x4c);
    *(uint *)(iVar4 + 0x10) =
         ((uint)*(ushort *)(&lld_scan_max_aux_dur_tab + (uint)*(byte *)(iVar4 + 0x55) * 2) +
         *(int *)(iVar4 + 0x50)) * 2 + (uint)_sdk_cfg_priv_opts;
    bVar2 = DAT_00015033;
    bVar6 = DAT_00015032;
    if (DAT_00015032 < *(byte *)(iVar4 + 0x16)) {
      bVar6 = *(byte *)(iVar4 + 0x16);
    }
    *(byte *)(iVar4 + 0x16) = bVar6;
    *(ushort *)(iVar4 + 0x14) = bVar2 & 0xf | 0x2000;
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar4,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar5 == 0) {
      bVar2 = *(byte *)(iVar4 + 0x55);
      uVar8 = *(uint *)(iVar4 + 0x50);
      uVar10 = (uint)bVar2 << 4;
      if ((uVar10 & 0xffffffcf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))("lld_scan.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = (uint)bVar1 * 0x5a;
      uVar9 = *(ushort *)(iVar5 + iVar7 + 4);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar7 + 4) = uVar9 & 0xffcf | (ushort)uVar10;
      uVar9 = *(ushort *)(&lld_scan_max_aux_dur_tab + (uint)bVar2 * 2);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + 0x20 + iVar5) = (ushort)(((uint)uVar9 + uVar8 + 0x270) / 0x271) & 0xff;
      uVar9 = 0x672 - *(short *)(iVar4 + 0x36);
      if ((uVar9 & 0xf800) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x6c0,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar5 + iVar7 + 0x28);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar7 + 0x28) = uVar9 | uVar3 & 0xf800;
      if (uVar8 < 0x4000) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(short *)(iVar5 + iVar7 + 0x1a) = (short)(uVar8 + 1 >> 1);
      }
      else {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar7 + 0x1a) = (ushort)((uVar8 + 0x270) / 0x271) & 0xff | 0x8000;
      }
      uVar8 = (uint)*(byte *)(iVar4 + 0x54) << 10;
      if ((uVar8 & 0x30000) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x635,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar9 = *(ushort *)(iVar5 + iVar7 + 0x26);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + iVar7 + 0x26) = uVar9 & 0x3ff | (ushort)uVar8;
      if (*(char *)(iVar4 + 0x6f) != -1) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)(iVar7 + 0x14 + iVar5) = 0;
      }
      if ((*(char *)(iVar4 + 0x3d) == '\x03') && (*(char *)(iVar4 + 0x39) == '\x01')) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar9 = *(ushort *)(iVar5 + iVar7);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar7 + iVar5) = uVar9 & 0xffe0 | 10;
      }
      *(undefined1 *)(iVar4 + 0x43) = 0;
      goto _L598;
    }
    if (*(char *)(iVar4 + 0x3d) == '\x03') {
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
      if (*(char *)(iVar5 + 0x18) == '\0') {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x96e,*(code **)(_r_plf_funcs_p + 8));
      }
      (**(code **)(_r_ip_funcs_p + 0x448))(param_1,*(code **)(_r_ip_funcs_p + 0x448));
      *(undefined1 *)(iVar4 + 0x3e) = 0;
      *(undefined1 *)(iVar4 + 0x3d) = 0;
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x7a0))(param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7a0));
_L598:
                    /* WARNING: Could not recover jumptable at 0x00012c02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x7fc))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x7fc));
  return;
}

