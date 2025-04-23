/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx_adv_rep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx_adv_rep(uint param_1,undefined1 param_2,int param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  code *pcVar5;
  int iVar6;
  undefined1 uVar7;
  int iVar8;
  void *pvVar9;
  undefined4 uVar10;
  char cVar11;
  int iVar12;
  
  iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  param_3 = param_3 * 0x14;
  sVar2 = *(short *)(param_3 + 0x12 + iVar8);
  if (*(char *)(iVar6 + 0x6e) != -1) {
    iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar12 = param_3 + 2;
    uVar3 = *(ushort *)(iVar8 + iVar12);
    if (((uVar3 & 0x10) == 0) || ((*(byte *)(iVar6 + 0x6d) & 4) != 0)) {
      if (*(byte *)(iVar6 + 0x6d) != 0x15) goto _L156;
_L154:
      pvVar9 = (void *)r_emi_get_mem_addr_by_offset((ushort)*(byte *)(param_4 + 2) + sVar2);
      memcpy((void *)(iVar6 + 0x62),pvVar9,6);
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      *(byte *)(iVar6 + 0x59) = (byte)(*(ushort *)(iVar8 + iVar12) >> 6) & 1;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      if (((*(ushort *)(iVar8 + iVar12) >> 6 & 1) == 0) &&
         ((*(char *)(iVar6 + 0x70) == '\0' || ((*(byte *)(iVar6 + 0x67) & 0xc0) == 0xc0)))) {
_L157:
        *(undefined1 *)(iVar6 + 0x6e) = 0xff;
        goto _L151;
      }
    }
    else {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      if (((*(ushort *)(param_3 + 0x10 + iVar8) & 0x300) != 0) ||
         ((*(byte *)(iVar6 + 0x6d) & 0x10) != 0)) goto _L157;
_L156:
      if ((*(ushort *)(param_4 + 6) & 0x200) != 0) goto _L154;
    }
    if (*(char *)(param_4 + 8) != -1) {
      *(byte *)(iVar6 + 0x58) = (byte)(uVar3 >> 7) & 1;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar4 = *(undefined2 *)(param_3 + 0xe + iVar8);
      *(char *)(iVar6 + 0x6b) = (char)((uVar3 & 0x10) >> 4);
      *(undefined2 *)(iVar6 + 0x5a) = uVar4;
    }
    if (*(char *)(iVar6 + 0x3d) != '\x01') {
      pvVar9 = (void *)r_ke_msg_alloc(0x201,0,0xff,0x2c);
      pcVar5 = _lld_scan_map_legacy_pdu_to_evt_type;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar7 = (*pcVar5)(*(ushort *)(param_3 + 6 + iVar8) & 0xff);
      *(undefined1 *)(iVar6 + 0x74) = uVar7;
      memcpy(pvVar9,(void *)(iVar6 + 0x58),0x2c);
      cVar11 = *(char *)(iVar6 + 0x6e);
      if (cVar11 == '\x02') {
_L160:
        r_lld_ext_scan_dynamic_pti_process_eco(iVar6,cVar11);
      }
      else if (cVar11 == '\0') {
        cVar11 = '\x03';
        goto _L160;
      }
      cVar11 = *(char *)(param_4 + 5);
      *(char *)((int)pvVar9 + 0x20) = cVar11;
      if (cVar11 != '\0') {
        *(short *)((int)pvVar9 + 0x22) = sVar2;
        uVar10 = r_emi_get_mem_addr_by_offset(sVar2);
        *(undefined4 *)((int)pvVar9 + 0x24) = uVar10;
        *(undefined1 *)((int)pvVar9 + 0x28) = *(undefined1 *)(param_4 + 4);
        bVar1 = *(byte *)(_p_lld_env + 0xd8);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
        *(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar8) = 0;
      }
      *(undefined1 *)((int)pvVar9 + 0x14) = *(undefined1 *)(_lld_scan_env + 0xd);
      r_ke_msg_send(pvVar9);
    }
    if (*(char *)(iVar6 + 0x6e) != -1) goto _L166;
  }
_L151:
  *(undefined2 *)(iVar6 + 0x36) = 0x673;
  *(undefined1 *)(iVar6 + 0x3d) = 0;
  *(undefined1 *)(iVar6 + 0x3e) = 0;
_L166:
  *(undefined1 *)(iVar6 + 0x3f) = param_2;
  iVar8 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar8 + 0x28) & 8) != 0) {
    iVar8 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar8 + 0x2c) < 3) {
      r_ble_log_internal_x1
                (0x40a1000d,
                 (uint)*(byte *)(iVar6 + 0x6e) << 0x18 | (uint)*(byte *)(iVar6 + 0x6d) << 0x10 |
                 param_1 | (uint)*(byte *)(iVar6 + 0x3d) << 8);
      return;
    }
  }
  return;
}

