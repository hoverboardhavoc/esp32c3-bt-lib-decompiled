/*
 * Last changed at upstream commit 976ca00e43905df9e910b400a9e17c311b085ce2
 * https://github.com/espressif/esp32c3-bt-lib/commit/976ca00e43905df9e910b400a9e17c311b085ce2
 * Upstream date: 2022-11-03 19:06:39 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ef8a115a) - Added config to disable scan backoff - Fixed llm_scan.c assert at line 1485 during controller deinit if duplicate scan is not stopped - Call pll track in controller task
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_hack(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar9 = *(int *)(param_1 * 4 + _lld_scan_env);
  while (uVar3 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                           (*(undefined1 *)(iVar9 + 0x38),*(code **)(_r_ip_funcs_p + 0x2a4)),
        uVar3 != 0) {
    uVar8 = (uint)*(byte *)(_p_lld_env + 0xd8);
    (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = uVar8 * 0x14;
    if (*(ushort *)(iVar9 + 0x36) < 0x673) {
      iVar10 = iVar4 + 4;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar7 = *(ushort *)(iVar5 + iVar4 + 2);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (6 < (*(ushort *)(iVar5 + iVar10) & 0xf)) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar2 = *(ushort *)(iVar4 + 0x10 + iVar5);
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar3 = (uint)((uVar2 & 0x3f) < *(ushort *)(iVar4 + iVar10) >> 8);
      }
      if (((uVar7 & 0x602d) == 0) && (uVar3 != 0)) {
        uStack_44 = 0xff;
        *(undefined1 *)(iVar9 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar7 = *(ushort *)(iVar4 + iVar10) & 0xf;
        if (((*(ushort *)(iVar4 + iVar10) & 8) != 0) || ((uVar7 - 3 & 0xfd) == 0)) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_scan.c",0x1c0,*(code **)(_r_plf_funcs_p + 8));
        }
        if (uVar7 < 7) {
          pcVar6 = *(code **)(_r_ip_funcs_p + 0x420);
        }
        else {
          pcVar6 = *(code **)(_r_ip_funcs_p + 0x40c);
        }
        (*pcVar6)(param_1,uVar7,uVar8,&uStack_4c,pcVar6);
        (**(code **)(_r_ip_funcs_p + 0x424))
                  (param_1,uVar7,uVar8,&uStack_4c,*(code **)(_r_ip_funcs_p + 0x424));
      }
      else if ((_DAT_60031048 & 8) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x428))(param_1,*(code **)(_r_ip_funcs_p + 0x428));
      }
    }
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  }
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar9 = ((uint)bVar1 * 9 & 0xff) * 0xe;
  if (*(short *)(iVar4 + iVar9) < 0) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar7 = *(ushort *)(iVar4 + iVar9);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar9 + iVar4) = uVar7 & 0x7fff;
  }
  return;
}

