/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar13 = *(int *)(param_1 * 4 + _lld_scan_env);
  do {
    uVar8 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar13 + 0x38));
    if (uVar8 == 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar9 + iVar13) < 0) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar9 + iVar13);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar9 + iVar13) = uVar2 & 0x7fff;
      }
      return;
    }
    uVar15 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar9 = uVar15 * 0x14;
    uVar3 = *(undefined2 *)(iVar10 + iVar9 + 0x12);
    if (*(ushort *)(iVar13 + 0x36) < 0x673) {
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar10 + iVar9 + 2);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
      iVar14 = iVar9 + 4;
      uVar4 = *(ushort *)(iVar10 + iVar14);
      uVar6 = uVar4 & 0xf;
      uVar12 = uVar8;
      if (uVar6 < 7) {
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          r_lld_ext_scan_dynamic_pti_reset(iVar13);
        }
        uVar7 = uVar8;
        if ((uVar6 - 3 & 0xfd) != 0) goto _L559;
      }
      else {
        iVar10 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar9 + 0x10 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar7 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar9 + iVar14) >> 8);
        if (uVar6 < 9) {
_L559:
          uVar12 = (uint)(uVar6 == 8);
        }
      }
      iVar9 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar9 + 0x18) == '\0') && (6 < uVar6)) {
        uVar12 = uVar8;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar7 != 0)) && (uVar12 == 0)) {
        iVar9 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar9 + 0x28) & 8) != 0) &&
           (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40a1000a,
                     (uint)uVar6 << 0x10 |
                     (uint)*(byte *)(iVar13 + 0x3d) << 0x18 | uVar15 << 8 | param_1);
        }
        uStack_44 = 0xff;
        uStack_4c = 0;
        uStack_48 = 0;
        *(undefined1 *)(iVar13 + 0x43) = 1;
        if (((uVar4 & 8) != 0) || ((uVar6 - 3 & 0xfd) == 0)) {
          r_assert_err(0,"lld_scan.c",0x263);
        }
        if (uVar6 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_1,uVar6,uVar15,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_1,uVar6,uVar15,&uStack_4c);
        iVar9 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar9 + 0x28) & 8) != 0) &&
           (iVar9 = r_sdk_config_get_opts_ext(), *(byte *)(iVar9 + 0x2c) < 2)) {
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar2 = *(ushort *)(iVar9 + iVar14);
          uVar11 = r_emi_get_mem_addr_by_offset(uVar3);
          r_ble_log_internal_hex(0x20a1000c,uVar2 >> 8,uVar11);
        }
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_1),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar13);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

