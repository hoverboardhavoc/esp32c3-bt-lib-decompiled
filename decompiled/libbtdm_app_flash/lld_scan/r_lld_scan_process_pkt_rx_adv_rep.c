/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_adv_rep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_adv_rep(uint param_1,undefined1 param_2,int param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  code *pcVar6;
  int iVar7;
  undefined1 uVar8;
  int iVar9;
  void *pvVar10;
  undefined4 uVar11;
  int iVar12;
  
  iVar7 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
  param_3 = param_3 * 0x14;
  sVar3 = *(short *)(iVar9 + param_3 + 0x12);
  if (*(char *)(iVar7 + 0x6e) != -1) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar12 = param_3 + 2;
    uVar4 = *(ushort *)(iVar9 + iVar12);
    if (((uVar4 & 0x10) == 0) || ((*(byte *)(iVar7 + 0x6d) & 4) != 0)) {
_L157:
      if ((*(char *)(iVar7 + 0x6d) == '\x15') || ((*(ushort *)(param_4 + 6) & 0x200) != 0)) {
        pvVar10 = (void *)r_emi_get_mem_addr_by_offset((ushort)*(byte *)(param_4 + 2) + sVar3);
        memcpy((void *)(iVar7 + 0x62),pvVar10,6);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        *(byte *)(iVar7 + 0x59) = (byte)(*(ushort *)(iVar9 + iVar12) >> 6) & 1;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        if (((*(ushort *)(iVar9 + iVar12) >> 6 & 1) == 0) &&
           ((*(char *)(iVar7 + 0x70) == '\0' || ((*(byte *)(iVar7 + 0x67) & 0xc0) == 0xc0))))
        goto _L161;
      }
      if (*(char *)(param_4 + 8) != -1) {
        *(byte *)(iVar7 + 0x58) = (byte)(uVar4 >> 7) & 1;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(undefined2 *)(iVar9 + param_3 + 0xe);
        *(bool *)(iVar7 + 0x6b) = (uVar4 & 0x10) != 0;
        *(undefined2 *)(iVar7 + 0x5a) = uVar5;
      }
      if (*(char *)(iVar7 + 0x3d) != '\x01') {
        pvVar10 = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
        pcVar6 = _rwip_rf;
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar8 = (*pcVar6)(*(ushort *)(param_3 + 6 + iVar9) & 0xff);
        *(undefined1 *)(iVar7 + 0x74) = uVar8;
        memcpy(pvVar10,(void *)(iVar7 + 0x58),0x2c);
        if (*(char *)(iVar7 + 0x6e) == '\x02') {
          uVar11 = 2;
_L164:
          r_lld_ext_scan_dynamic_pti_process_eco(iVar7,uVar11);
        }
        else {
          uVar11 = 3;
          if (*(char *)(iVar7 + 0x6e) == '\0') goto _L164;
        }
        cVar1 = *(char *)(param_4 + 5);
        *(char *)((int)pvVar10 + 0x20) = cVar1;
        if (cVar1 != '\0') {
          *(short *)((int)pvVar10 + 0x22) = sVar3;
          uVar11 = r_emi_get_mem_addr_by_offset(sVar3);
          *(undefined4 *)((int)pvVar10 + 0x24) = uVar11;
          *(undefined1 *)((int)pvVar10 + 0x28) = *(undefined1 *)(param_4 + 4);
          bVar2 = *(byte *)(_p_lld_env + 0xd8);
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          *(undefined2 *)((uint)bVar2 * 0x14 + 0x12 + iVar9) = 0;
        }
        *(undefined1 *)((int)pvVar10 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
        r_ke_msg_send(pvVar10);
      }
      if (*(char *)(iVar7 + 0x6e) != -1) goto _L170;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      if (((*(ushort *)(iVar9 + param_3 + 0x10) & 0x300) == 0) &&
         ((*(byte *)(iVar7 + 0x6d) & 0x10) == 0)) goto _L157;
_L161:
      *(undefined1 *)(iVar7 + 0x6e) = 0xff;
    }
  }
  *(undefined2 *)(iVar7 + 0x36) = 0x673;
  *(undefined1 *)(iVar7 + 0x3d) = 0;
  *(undefined1 *)(iVar7 + 0x3e) = 0;
_L170:
  *(undefined1 *)(iVar7 + 0x3f) = param_2;
  iVar9 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar9 + 0x28) & 8) != 0) {
    iVar9 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar9 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40a1000d,
                 (uint)*(byte *)(iVar7 + 0x3d) << 8 |
                 (uint)*(byte *)(iVar7 + 0x6e) << 0x18 | (uint)*(byte *)(iVar7 + 0x6d) << 0x10 |
                 param_1);
      return;
    }
  }
  return;
}

