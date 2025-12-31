/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_ch_map_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_ch_map_update(void)

{
  bool bVar1;
  code cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  iVar4 = r_lld_read_clock();
  iVar6 = _p_llm_env;
  iVar5 = r_lld_ch_assess_data_get();
  cVar2 = r_hci_ble_conhdl_unregister;
  iVar13 = _p_llm_env;
  uVar14 = (uint)_DAT_000120c6;
  uVar15 = (uint)_r_lld_res_list_peer_update_hack;
  iVar3 = iVar6 + 0x1d;
  pcVar7 = (char *)(iVar5 + 0x94);
  uVar8 = 0;
  do {
    iVar9 = ((int)uVar8 >> 3) + iVar6;
    uVar12 = uVar8 & 7;
    if (((int)(uint)*(byte *)(iVar9 + 0x18) >> uVar12 & 1U) == 0) {
_L430:
      bVar11 = ~(byte)(1 << uVar12) & *(byte *)(iVar9 + 0x1d);
_L429:
      *(byte *)(iVar9 + 0x1d) = bVar11;
    }
    else if (*(char *)(iVar13 + 0xd9) != '\0') {
      uVar10 = iVar4 - *(int *)(uVar8 * 4 + iVar5) & 0xfffffff;
      if (uVar10 < uVar14) {
        if (*pcVar7 <= (char)cVar2) goto _L430;
      }
      else {
        *pcVar7 = '\0';
        if (uVar15 < uVar10) {
          bVar11 = (byte)(1 << uVar12) | *(byte *)(iVar9 + 0x1d);
          goto _L429;
        }
      }
    }
    uVar8 = uVar8 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar8 != 0x25);
  uVar8 = r_co_nb_good_le_channels(iVar3);
  if (uVar8 < 2) {
    uVar14 = 0;
    do {
      iVar13 = ((int)uVar14 >> 3) + iVar6;
      uVar15 = uVar14 & 7;
      if (((int)(uint)*(byte *)(iVar13 + 0x18) >> uVar15 & 1U) != 0) {
        if (((int)(uint)*(byte *)(iVar13 + 0x1d) >> uVar15 & 1U) == 0) {
          *(byte *)(iVar13 + 0x1d) = *(byte *)(iVar13 + 0x1d) | (byte)(1 << uVar15);
          if (uVar8 == 1) break;
          uVar8 = 1;
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != 0x25);
  }
  r_lld_ch_map_set(iVar3);
  bVar1 = false;
  for (uVar8 = 0; iVar6 = r_sdk_config_get_opts(), (int)uVar8 < (int)(uint)*(byte *)(iVar6 + 0xd);
      uVar8 = uVar8 + 1) {
    iVar6 = *(int *)(_p_llm_env + 8) + uVar8 * 0x44;
    if ((*(char *)(iVar6 + 0x40) == '\t') && (*(char *)(iVar6 + 0x28) == '\0')) {
      r_ke_msg_send_basic(2,(uVar8 & 0xff) << 8 | 1,0);
      bVar1 = true;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar8 * 0x44 + 0x40) == '\f') {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar6 + 0x18) == '\0') {
        r_assert_err(0,"llm.c",0x527);
      }
      r_lld_per_adv_ch_map_update(uVar8 & 0xff,iVar3);
    }
  }
  if (bVar1) {
    r_ke_timer_set(4,0,(uint)_r_lld_white_list_add * 100);
  }
  else {
    *(undefined1 *)(_p_llm_env + 0x22) = 0;
  }
  r_ble_log_internal_hex(0x40080149,5,iVar3);
  return;
}

