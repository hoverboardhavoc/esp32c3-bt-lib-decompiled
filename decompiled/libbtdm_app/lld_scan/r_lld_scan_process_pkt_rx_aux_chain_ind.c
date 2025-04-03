/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_aux_chain_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_aux_chain_ind(int param_1,int param_2,char *param_3)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  short *psVar7;
  void *__src;
  undefined1 *puVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined4 uStack_24;
  
  iVar4 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  bVar1 = param_3[5];
  sVar2 = *(short *)(iVar6 + param_2 * 0x14 + 0x12);
  uVar10 = (uint)*(ushort *)(iVar4 + 0x36) + (uint)bVar1;
  iVar6 = uVar10 * 0x10000;
  *(char *)(iVar4 + 0x41) = *(char *)(iVar4 + 0x41) + '\x01';
  *(short *)(iVar4 + 0x36) = (short)((uint)iVar6 >> 0x10);
  if (0x672 < (uVar10 & 0xffff)) {
    *(undefined1 *)(iVar4 + 0x6e) = 2;
    param_3[5] = (bVar1 + 0x72) - (char)((uint)iVar6 >> 0x10);
    goto _L526;
  }
  if (*param_3 == '\0') {
    uVar9 = 0;
    if ((*(byte *)(iVar4 + 0x6d) & 8) == 0) {
      uVar9 = 2;
    }
    *(undefined1 *)(iVar4 + 0x6e) = uVar9;
    goto _L526;
  }
  uVar3 = *(ushort *)(param_3 + 6);
  sVar5 = 0;
  if ((uVar3 & 0x100) != 0) {
    sVar5 = 6;
  }
  if ((uVar3 & 0x200) != 0) {
    sVar5 = sVar5 + 6;
  }
  if ((uVar3 & 0x400) != 0) {
    sVar5 = sVar5 + 1;
  }
  if ((int)((uint)uVar3 << 0x14) < 0) {
    psVar7 = (short *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (sVar2 + sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar4 + 0x34) == *psVar7) {
      sVar5 = sVar5 + 2;
_L499:
      if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x13)) {
        *(undefined1 *)(iVar4 + 0x6e) = 0;
        *(undefined1 *)(iVar4 + 0x3d) = 0;
        goto _L504;
      }
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (sVar2 + sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(&uStack_24,__src,3);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(param_2 * 0x14 + 2 + iVar6) >> 9 & 1) == 0) {
        if (*(byte *)(iVar4 + 0x41) < 7) {
          iVar6 = (**(code **)(_r_ip_funcs_p + 0x224))
                            (iVar4 + 0x48,param_2,uStack_24,*(code **)(_r_ip_funcs_p + 0x224));
          uVar9 = 1;
          if (iVar6 != 0) goto _L525;
        }
        *(undefined1 *)(iVar4 + 0x6e) = 2;
      }
      else {
        *(undefined4 *)(iVar4 + 0x2c) = uStack_24;
        uVar9 = 2;
_L525:
        *(undefined1 *)(iVar4 + 0x3e) = uVar9;
      }
      *(undefined1 *)(iVar4 + 0x3d) = 3;
      sVar5 = sVar5 + 3;
_L504:
      if ((int)((uint)*(ushort *)(param_3 + 6) << 0x12) < 0) {
        sVar5 = sVar5 + 0x12;
      }
      if (-1 < (int)((uint)*(ushort *)(param_3 + 6) << 0x11)) {
        return;
      }
      puVar8 = (undefined1 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))(sVar2 + sVar5,*(code **)(_r_plf_funcs_p + 0xbc))
      ;
      *(undefined1 *)(iVar4 + 0x73) = *puVar8;
      return;
    }
  }
  else if ((*(byte *)(iVar4 + 0x6d) & 8) != 0) goto _L499;
  *(undefined1 *)(iVar4 + 0x6e) = 2;
  param_3[5] = '\0';
_L526:
  *(undefined1 *)(iVar4 + 0x3d) = 0;
  return;
}

