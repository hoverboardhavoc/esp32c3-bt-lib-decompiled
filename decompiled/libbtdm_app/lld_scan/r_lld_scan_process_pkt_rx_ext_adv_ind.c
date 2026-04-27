/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_ext_adv_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_ext_adv_ind(int param_1,int param_2,char *param_3)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  void *pvVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  byte bVar10;
  undefined1 uVar11;
  ushort uVar12;
  code *pcVar13;
  short sVar14;
  int iVar15;
  uint auStack_34 [4];
  
  iVar4 = *(int *)(_lld_scan_env + param_1 * 4);
  if (*(char *)(iVar4 + 0x3d) != '\0') {
    return;
  }
  iVar15 = param_2 * 0x14;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  sVar1 = *(short *)(iVar15 + 0x12 + iVar6);
  memset((void *)(iVar4 + 0x58),0,0x2c);
  iVar6 = _r_ip_funcs_p;
  *(undefined1 *)(iVar4 + 0x41) = 0;
  pcVar13 = *(code **)(iVar6 + 0x3d8);
  *(undefined2 *)(iVar4 + 0x36) = 0;
  (*pcVar13)(iVar4,0,pcVar13);
  *(undefined1 *)(iVar4 + 0x6e) = 1;
  *(undefined1 *)(iVar4 + 0x71) = *(undefined1 *)(iVar4 + 0x3b);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar15 + 0x10 + iVar6) >> 6;
  uVar12 = uVar2 & 3;
  param_3[1] = (char)uVar12;
  if (uVar12 == 1) {
    bVar10 = *(byte *)(iVar4 + 0x6d) | 1;
_L368:
    *(byte *)(iVar4 + 0x6d) = bVar10;
  }
  else if (uVar12 == 2) {
    bVar10 = *(byte *)(iVar4 + 0x6d) | 2;
    goto _L368;
  }
  *(undefined1 *)(iVar4 + 0x6a) = 0;
  if (*param_3 == '\0') {
    *(undefined1 *)(iVar4 + 0x6e) = 0;
  }
  else {
    uVar12 = *(ushort *)(param_3 + 6);
    sVar14 = 0;
    if ((uVar12 & 0x100) != 0) {
      if (((uVar2 & 3) == 0) && ((*(char *)(iVar4 + 0x3b) == '\0' || ((uVar12 & 0x1000) == 0)))) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        param_3[8] = (byte)(*(ushort *)(iVar15 + 4 + iVar6) >> 6) & 1;
        pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   ((ushort)(byte)param_3[3] + sVar1,
                                    *(code **)(_r_plf_funcs_p + 0xbc));
        memcpy((void *)(iVar4 + 0x5c),pvVar7,6);
      }
      else {
        *(ushort *)(param_3 + 6) = uVar12 & 0xfeff;
      }
      sVar14 = 6;
    }
    uVar2 = *(ushort *)(param_3 + 6);
    if ((uVar2 & 0x200) != 0) {
      if ((param_3[1] == '\0') && ((*(char *)(iVar4 + 0x3b) == '\0' || ((uVar2 & 0x1000) == 0)))) {
        *(byte *)(iVar4 + 0x6d) = *(byte *)(iVar4 + 0x6d) | 4;
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(byte *)(iVar4 + 0x70) = (byte)(*(ushort *)(iVar15 + 4 + iVar6) >> 7) & 1;
        param_3[2] = (char)sVar14;
      }
      else {
        *(ushort *)(param_3 + 6) = uVar2 & 0xfdff;
      }
      sVar14 = sVar14 + 6;
    }
    if ((*(ushort *)(param_3 + 6) & 0x400) != 0) {
      sVar14 = sVar14 + 1;
    }
    if ((*(ushort *)(param_3 + 6) >> 0xb & 1) != 0) {
      sVar5 = sVar1 + sVar14;
      sVar14 = sVar14 + 2;
      puVar8 = (undefined2 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))(sVar5,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *puVar8;
      *(undefined2 *)(iVar4 + 0x34) = uVar3;
      *(undefined2 *)(iVar4 + 0x68) = uVar3;
      *(undefined1 *)(iVar4 + 0x6a) = 1;
    }
    if ((*(ushort *)(param_3 + 6) & 0x1000) == 0) {
      *(char *)(iVar4 + 0x6e) = -(*(char *)(iVar4 + 0x6f) == -1);
      *(undefined1 *)(iVar4 + 0x72) = 4;
    }
    else {
      pvVar7 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 (sVar1 + sVar14,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_34,pvVar7,3);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(ushort *)(iVar15 + 2 + iVar6) >> 9 & 1) == 0) {
        if (2 < (auStack_34[0] >> 0x15 & 7)) {
_L336:
          *(undefined1 *)(iVar4 + 0x6e) = 0xff;
          return;
        }
        iVar6 = (**(code **)(_r_ip_funcs_p + 0x224))
                          (iVar4 + 0x48,param_2,*(code **)(_r_ip_funcs_p + 0x224));
        uVar11 = 1;
        if (iVar6 == 0) goto _L336;
      }
      else {
        *(uint *)(iVar4 + 0x2c) = auStack_34[0];
        uVar11 = 2;
      }
      *(undefined1 *)(iVar4 + 0x3e) = uVar11;
      *(undefined1 *)(iVar4 + 0x3d) = 1;
      sVar14 = sVar14 + 3;
    }
    uVar2 = *(ushort *)(param_3 + 6);
    if ((uVar2 & 0x2000) != 0) {
      sVar14 = sVar14 + 0x12;
    }
    if ((uVar2 & 0x4000) == 0) {
      uVar11 = 0x7f;
    }
    else {
      if ((*(char *)(iVar4 + 0x3b) != '\0') && ((param_3[1] != '\0' || ((uVar2 & 0x1000) != 0))))
      goto _L342;
      puVar9 = (undefined1 *)
               (**(code **)(_r_plf_funcs_p + 0xbc))
                         (sVar1 + sVar14,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar11 = *puVar9;
    }
    *(undefined1 *)(iVar4 + 0x73) = uVar11;
  }
_L342:
  *(char *)(iVar4 + 0x6f) = param_3[8];
  param_3[5] = '\0';
  return;
}

