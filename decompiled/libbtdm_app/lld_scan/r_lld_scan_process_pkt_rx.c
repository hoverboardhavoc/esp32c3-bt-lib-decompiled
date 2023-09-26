/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar9 = *(int *)(param_1 * 4 + _lld_scan_env);
  while (uVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                           (*(undefined1 *)(iVar9 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4)),
        uVar4 != 0) {
    uVar11 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar5 = uVar11 * 0x14;
    if (*(ushort *)(iVar9 + 0x36) < 0x673) {
      iVar10 = iVar5 + 4;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar8 = *(ushort *)(iVar6 + iVar5 + 2);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar6 + iVar10) & 0xf) < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        if (bVar2 != 0) {
          (**(code **)(_r_ip_funcs_p + 0x930))(iVar9,*(code **)(_r_ip_funcs_p + 0x930));
          uVar4 = (uint)bVar2;
        }
      }
      else {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = *(ushort *)(iVar5 + 0x10 + iVar6);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = (uint)((uVar3 & 0x3f) < *(ushort *)(iVar5 + iVar10) >> 8);
      }
      if (((uVar8 & 0x602d) == 0) && (uVar4 != 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar9 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar8 = *(ushort *)(iVar5 + iVar10) & 0xf;
        if (((*(ushort *)(iVar5 + iVar10) & 8) != 0) || ((uVar8 - 3 & 0xfd) == 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x230,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar8 < 7) {
          pcVar7 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar7 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar7)(param_1,uVar8,uVar11,&uStack_4c,pcVar7);
        (**(code **)(_r_ip_funcs_p + 0x424))
                  (param_1,uVar8,uVar11,&uStack_4c,*(code **)(_r_ip_funcs_p + 0x424));
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              ((**(code **)(_r_ip_funcs_p + 0x428))(param_1,*(code **)(_r_ip_funcs_p + 0x428)),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        (**(code **)(_r_ip_funcs_p + 0x930))(iVar9,*(code **)(_r_ip_funcs_p + 0x930));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if (*(short *)(iVar5 + iVar9) < 0) {
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar8 = *(ushort *)(iVar5 + iVar9);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar9) = uVar8 & 0x7fff;
  }
  return;
}

