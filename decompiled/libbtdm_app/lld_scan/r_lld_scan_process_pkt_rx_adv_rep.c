/*
 * Last changed at upstream commit 27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * https://github.com/espressif/esp32c3-bt-lib/commit/27af69ccbb02f3b820436f47eaa0b1cd544edfbc
 * Upstream date: 2023-09-26 16:09:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(c8aa206)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_process_pkt_rx_adv_rep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_adv_rep(int param_1,undefined1 param_2,int param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined1 uVar7;
  int iVar8;
  void *pvVar9;
  undefined4 uVar10;
  code *pcVar11;
  int iVar12;
  
  iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  param_3 = param_3 * 0x14;
  sVar3 = *(short *)(iVar8 + param_3 + 0x12);
  if (*(char *)(iVar6 + 0x6e) != -1) {
    iVar12 = param_3 + 2;
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar8 + iVar12);
    if (((uVar4 & 0x10) == 0) || ((*(byte *)(iVar6 + 0x6d) & 4) != 0)) {
      if ((*(char *)(iVar6 + 0x6d) == '\x15') || ((*(ushort *)(param_4 + 6) & 0x200) != 0)) {
        pvVar9 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                   ((ushort)*(byte *)(param_4 + 2) + sVar3,
                                    *(code **)(_r_plf_funcs_p + 0xbc));
        memcpy((void *)(iVar6 + 0x62),pvVar9,6);
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        *(byte *)(iVar6 + 0x59) = (byte)(*(ushort *)(iVar8 + iVar12) >> 6) & 1;
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        if (((*(ushort *)(iVar8 + iVar12) >> 6 & 1) == 0) &&
           ((*(char *)(iVar6 + 0x70) == '\0' || ((*(byte *)(iVar6 + 0x67) & 0xc0) == 0xc0))))
        goto _L177;
      }
      if (*(char *)(param_4 + 8) != -1) {
        pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
        *(byte *)(iVar6 + 0x58) = (byte)(uVar4 >> 7) & 1;
        iVar8 = (*pcVar11)(0x1000,pcVar11);
        uVar5 = *(undefined2 *)(iVar8 + param_3 + 0xe);
        *(bool *)(iVar6 + 0x6b) = (uVar4 & 0x10) != 0;
        *(undefined2 *)(iVar6 + 0x5a) = uVar5;
      }
      if (*(char *)(iVar6 + 0x3d) != '\x01') {
        pvVar9 = (void *)(**(code **)(_r_modules_funcs_p + 200))
                                   (0x201,0,0xff,0x2c,*(code **)(_r_modules_funcs_p + 200));
        pcVar11 = _rwip_rf;
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar7 = (*pcVar11)(*(ushort *)(param_3 + 6 + iVar8) & 0xff);
        *(undefined1 *)(iVar6 + 0x74) = uVar7;
        memcpy(pvVar9,(void *)(iVar6 + 0x58),0x2c);
        if (*(char *)(iVar6 + 0x6e) == '\x02') {
          uVar10 = 2;
_L180:
          (**(code **)(_r_ip_funcs_p + 0x3d8))(iVar6,uVar10,*(code **)(_r_ip_funcs_p + 0x3d8));
        }
        else {
          uVar10 = 3;
          if (*(char *)(iVar6 + 0x6e) == '\0') goto _L180;
        }
        cVar1 = *(char *)(param_4 + 5);
        *(char *)((int)pvVar9 + 0x20) = cVar1;
        iVar8 = _r_plf_funcs_p;
        if (cVar1 != '\0') {
          *(short *)((int)pvVar9 + 0x22) = sVar3;
          uVar10 = (**(code **)(iVar8 + 0xbc))(sVar3,*(code **)(iVar8 + 0xbc));
          *(undefined4 *)((int)pvVar9 + 0x24) = uVar10;
          *(undefined1 *)((int)pvVar9 + 0x28) = *(undefined1 *)(param_4 + 4);
          bVar2 = *(byte *)(_p_lld_env + 0xd8);
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
          *(undefined2 *)((uint)bVar2 * 0x14 + 0x12 + iVar8) = 0;
        }
        *(undefined1 *)((int)pvVar9 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
        (**(code **)(_r_modules_funcs_p + 0xe0))(pvVar9,*(code **)(_r_modules_funcs_p + 0xe0));
      }
      if (*(char *)(iVar6 + 0x6e) != -1) goto _L183;
    }
    else {
_L177:
      *(undefined1 *)(iVar6 + 0x6e) = 0xff;
    }
  }
  *(undefined2 *)(iVar6 + 0x36) = 0x673;
  *(undefined1 *)(iVar6 + 0x3d) = 0;
_L183:
  *(undefined1 *)(iVar6 + 0x3f) = param_2;
  return;
}

