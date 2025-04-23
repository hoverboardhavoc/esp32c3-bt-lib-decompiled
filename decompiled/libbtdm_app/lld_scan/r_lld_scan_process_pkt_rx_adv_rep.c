/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_adv_rep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_adv_rep(int param_1,undefined1 param_2,int param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  char cVar10;
  code *pcVar11;
  int iVar12;
  
  iVar5 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  param_3 = param_3 * 0x14;
  sVar2 = *(short *)(param_3 + 0x12 + iVar7);
  if (*(char *)(iVar5 + 0x6e) != -1) {
    iVar12 = param_3 + 2;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar12);
    if (((uVar3 & 0x10) == 0) || ((*(byte *)(iVar5 + 0x6d) & 4) != 0)) {
      if (*(byte *)(iVar5 + 0x6d) != 0x15) goto _L107;
_L105:
      pvVar8 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                 ((ushort)*(byte *)(param_4 + 2) + sVar2,
                                  *(code **)(_r_plf_funcs_p + 0xbc));
      memcpy((void *)(iVar5 + 0x62),pvVar8,6);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      *(byte *)(iVar5 + 0x59) = (byte)(*(ushort *)(iVar7 + iVar12) >> 6) & 1;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (((*(ushort *)(iVar7 + iVar12) >> 6 & 1) == 0) &&
         ((*(char *)(iVar5 + 0x70) == '\0' || ((*(byte *)(iVar5 + 0x67) & 0xc0) == 0xc0)))) {
_L108:
        *(undefined1 *)(iVar5 + 0x6e) = 0xff;
        goto _L102;
      }
    }
    else {
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (((*(ushort *)(param_3 + 0x10 + iVar7) & 0x300) != 0) ||
         ((*(byte *)(iVar5 + 0x6d) & 0x10) != 0)) goto _L108;
_L107:
      if ((*(ushort *)(param_4 + 6) & 0x200) != 0) goto _L105;
    }
    if (*(char *)(param_4 + 8) != -1) {
      pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(byte *)(iVar5 + 0x58) = (byte)(uVar3 >> 7) & 1;
      iVar7 = (*pcVar11)(0x1000,pcVar11);
      uVar4 = *(undefined2 *)(param_3 + 0xe + iVar7);
      *(char *)(iVar5 + 0x6b) = (char)((uVar3 & 0x10) >> 4);
      *(undefined2 *)(iVar5 + 0x5a) = uVar4;
    }
    if (*(char *)(iVar5 + 0x3d) != '\x01') {
      pvVar8 = (void *)(**(code **)(_r_modules_funcs_p + 200))
                                 (0x201,0,0xff,0x2c,*(code **)(_r_modules_funcs_p + 200));
      pcVar11 = _r_osi_funcs_p;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar6 = (*pcVar11)(*(ushort *)(param_3 + 6 + iVar7) & 0xff);
      *(undefined1 *)(iVar5 + 0x74) = uVar6;
      memcpy(pvVar8,(void *)(iVar5 + 0x58),0x2c);
      cVar10 = *(char *)(iVar5 + 0x6e);
      if (cVar10 == '\x02') {
_L111:
        (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar5,cVar10,*(code **)(_r_ip_funcs_p + 0x3d8));
      }
      else if (cVar10 == '\0') {
        cVar10 = '\x03';
        goto _L111;
      }
      cVar10 = *(char *)(param_4 + 5);
      *(char *)((int)pvVar8 + 0x20) = cVar10;
      iVar7 = _r_plf_funcs_p;
      if (cVar10 != '\0') {
        *(short *)((int)pvVar8 + 0x22) = sVar2;
        uVar9 = (**(code **)(iVar7 + 0xbc))(sVar2,*(code **)(iVar7 + 0xbc));
        *(undefined4 *)((int)pvVar8 + 0x24) = uVar9;
        *(undefined1 *)((int)pvVar8 + 0x28) = *(undefined1 *)(param_4 + 4);
        bVar1 = *(byte *)(_p_lld_env + 0xd8);
        iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar7) = 0;
      }
      *(undefined1 *)((int)pvVar8 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
      (**(code **)(_r_modules_funcs_p + 0xe0))(pvVar8,*(code **)(_r_modules_funcs_p + 0xe0));
    }
    if (*(char *)(iVar5 + 0x6e) != -1) goto _L114;
  }
_L102:
  *(undefined2 *)(iVar5 + 0x36) = 0x673;
  *(undefined1 *)(iVar5 + 0x3d) = 0;
  *(undefined1 *)(iVar5 + 0x3e) = 0;
_L114:
  *(undefined1 *)(iVar5 + 0x3f) = param_2;
  return;
}

