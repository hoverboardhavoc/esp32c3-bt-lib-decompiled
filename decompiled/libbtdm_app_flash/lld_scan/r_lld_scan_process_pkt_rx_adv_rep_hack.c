/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_adv_rep_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_adv_rep_hack(int param_1,undefined1 param_2,int param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  code *pcVar7;
  int iVar8;
  undefined1 uVar9;
  int iVar10;
  void *pvVar11;
  undefined4 uVar12;
  int iVar13;
  
  iVar8 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
  param_3 = param_3 * 0x14;
  sVar3 = *(short *)(param_3 + 0x12 + iVar10);
  if (*(char *)(iVar8 + 0x6e) != -1) {
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar13 = param_3 + 2;
    uVar4 = *(ushort *)(iVar10 + iVar13);
    if (((uVar4 & 0x10) == 0) || ((*(byte *)(iVar8 + 0x6d) & 4) != 0)) {
_L160:
      if ((*(char *)(iVar8 + 0x6d) == '\x15') || ((*(ushort *)(param_4 + 6) & 0x200) != 0)) {
        pvVar11 = (void *)r_emi_get_mem_addr_by_offset((ushort)*(byte *)(param_4 + 2) + sVar3);
        memcpy((void *)(iVar8 + 0x62),pvVar11,6);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        *(byte *)(iVar8 + 0x59) = (byte)(*(ushort *)(iVar10 + iVar13) >> 6) & 1;
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        if (((*(ushort *)(iVar10 + iVar13) >> 6 & 1) == 0) &&
           ((*(byte *)(iVar8 + 0x70) == 0 || ((*(byte *)(iVar8 + 0x67) & 0xc0) == 0xc0)))) {
          *(undefined1 *)(iVar8 + 0x6e) = 0xff;
          r_ble_log_internal_x1
                    (0x40a10116,
                     (uint)*(byte *)(iVar8 + 0x6d) << 0x10 | (uint)*(byte *)(iVar8 + 0x70) << 0x18 |
                     (uint)uVar4);
          goto _L162;
        }
      }
      if (*(char *)(param_4 + 8) != -1) {
        *(byte *)(iVar8 + 0x58) = (byte)(uVar4 >> 7) & 1;
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar6 = *(undefined2 *)(param_3 + 0xe + iVar10);
        *(bool *)(iVar8 + 0x6b) = (uVar4 & 0x10) != 0;
        *(undefined2 *)(iVar8 + 0x5a) = uVar6;
      }
      if (*(char *)(iVar8 + 0x3d) != '\x01') {
        pvVar11 = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
        pcVar7 = _r_sdk_config_get_opts_ext;
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar9 = (*pcVar7)(*(ushort *)(param_3 + 6 + iVar10) & 0xff);
        *(undefined1 *)(iVar8 + 0x74) = uVar9;
        memcpy(pvVar11,(void *)(iVar8 + 0x58),0x2c);
        if (*(char *)(iVar8 + 0x6e) == '\x02') {
          uVar12 = 2;
_L167:
          r_lld_ext_scan_dynamic_pti_process_eco(iVar8,uVar12);
        }
        else {
          uVar12 = 3;
          if (*(char *)(iVar8 + 0x6e) == '\0') goto _L167;
        }
        cVar1 = *(char *)(param_4 + 5);
        *(char *)((int)pvVar11 + 0x20) = cVar1;
        if (cVar1 != '\0') {
          *(short *)((int)pvVar11 + 0x22) = sVar3;
          uVar12 = r_emi_get_mem_addr_by_offset(sVar3);
          *(undefined4 *)((int)pvVar11 + 0x24) = uVar12;
          *(undefined1 *)((int)pvVar11 + 0x28) = *(undefined1 *)(param_4 + 4);
          bVar2 = *(byte *)(_p_lld_env + 0xd8);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
          *(undefined2 *)((uint)bVar2 * 0x14 + 0x12 + iVar10) = 0;
        }
        *(undefined1 *)((int)pvVar11 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
        r_ke_msg_send(pvVar11);
      }
    }
    else {
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar5 = *(ushort *)(param_3 + 0x10 + iVar10);
      if (((uVar5 & 0x300) == 0) && ((*(byte *)(iVar8 + 0x6d) & 0x10) == 0)) goto _L160;
      *(undefined1 *)(iVar8 + 0x6e) = 0xff;
      r_ble_log_internal_x2(0x40a10115,CONCAT22(uVar5,uVar4));
    }
_L162:
    if (*(char *)(iVar8 + 0x6e) != -1) goto _L159;
  }
  *(undefined2 *)(iVar8 + 0x36) = 0x673;
  *(undefined1 *)(iVar8 + 0x3d) = 0;
  *(undefined1 *)(iVar8 + 0x3e) = 0;
_L159:
  *(undefined1 *)(iVar8 + 0x3f) = param_2;
  return;
}

