/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_rx_isr(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_1 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0x9a9);
    return;
  }
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  iVar11 = *(int *)(param_1 * 4 + _lld_scan_env);
  do {
    uVar7 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar11 + 0x38));
    if (uVar7 == 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar11 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar8 + iVar11) < 0) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar8 + iVar11);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar8 + iVar11) = uVar2 & 0x7fff;
      }
      return;
    }
    uVar12 = (uint)*(byte *)(_p_lld_env + 0xd8);
    r_emi_get_mem_addr_by_offset(0x1000);
    iVar8 = uVar12 * 0x14;
    if (*(ushort *)(iVar11 + 0x36) < 0x673) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar9 + iVar8 + 2);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar9 + iVar8 + 4);
      uVar5 = uVar3 & 0xf;
      uVar10 = uVar7;
      if (uVar5 < 7) {
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          r_lld_ext_scan_dynamic_pti_reset(iVar11);
        }
        uVar6 = uVar7;
        if ((uVar5 - 3 & 0xfd) != 0) goto _L554;
      }
      else {
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar4 = *(ushort *)(iVar8 + 0x10 + iVar9);
        iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar6 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar9 + iVar8 + 4) >> 8);
        if (uVar5 < 9) {
_L554:
          uVar10 = (uint)(uVar5 == 8);
        }
      }
      iVar8 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar8 + 0x18) == '\0') && (6 < uVar5)) {
        uVar10 = uVar7;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar6 != 0)) && (uVar10 == 0)) {
        uStack_44 = 0xff;
        uStack_4c = 0;
        uStack_48 = 0;
        *(undefined1 *)(iVar11 + 0x43) = 1;
        if (((uVar3 & 8) != 0) || ((uVar5 - 3 & 0xfd) == 0)) {
          r_assert_err(0,"lld_scan.c",0x25f);
        }
        if (uVar5 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_1,uVar5,uVar12,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_1,uVar5,uVar12,&uStack_4c);
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_1),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar11);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

