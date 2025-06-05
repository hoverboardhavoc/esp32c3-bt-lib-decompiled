/*
 * Last changed at upstream commit 3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * https://github.com/espressif/esp32c3-bt-lib/commit/3ff529142f6e2707d57b10eb87ac8d86e9098b88
 * Upstream date: 2025-06-05 11:04:06 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713a69)
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
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  iVar3 = r_lld_read_clock();
  iVar5 = _p_llm_env;
  iVar4 = r_lld_ch_assess_data_get();
  cVar2 = r_hci_ble_conhdl_unregister;
  iVar12 = _p_llm_env;
  uVar14 = (uint)_DAT_000120ba;
  uVar15 = (uint)_r_lld_res_list_peer_update_hack;
  iVar13 = iVar5 + 0x1d;
  pcVar6 = (char *)(iVar4 + 0x94);
  uVar7 = 0;
  do {
    iVar8 = ((int)uVar7 >> 3) + iVar5;
    uVar11 = uVar7 & 7;
    if (((int)(uint)*(byte *)(iVar8 + 0x18) >> uVar11 & 1U) == 0) {
_L417:
      bVar10 = ~(byte)(1 << uVar11) & *(byte *)(iVar8 + 0x1d);
_L416:
      *(byte *)(iVar8 + 0x1d) = bVar10;
    }
    else if (*(char *)(iVar12 + 0xd9) != '\0') {
      uVar9 = iVar3 - *(int *)(uVar7 * 4 + iVar4) & 0xfffffff;
      if (uVar9 < uVar14) {
        if (*pcVar6 <= (char)cVar2) goto _L417;
      }
      else {
        *pcVar6 = '\0';
        if (uVar15 < uVar9) {
          bVar10 = (byte)(1 << uVar11) | *(byte *)(iVar8 + 0x1d);
          goto _L416;
        }
      }
    }
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 != 0x25);
  uVar7 = r_co_nb_good_le_channels(iVar13);
  if (uVar7 < 2) {
    uVar14 = 0;
    do {
      iVar12 = ((int)uVar14 >> 3) + iVar5;
      uVar15 = uVar14 & 7;
      if (((int)(uint)*(byte *)(iVar12 + 0x18) >> uVar15 & 1U) != 0) {
        if (((int)(uint)*(byte *)(iVar12 + 0x1d) >> uVar15 & 1U) == 0) {
          *(byte *)(iVar12 + 0x1d) = *(byte *)(iVar12 + 0x1d) | (byte)(1 << uVar15);
          if (uVar7 == 1) break;
          uVar7 = 1;
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != 0x25);
  }
  r_lld_ch_map_set(iVar13);
  bVar1 = false;
  for (uVar7 = 0; iVar5 = r_sdk_config_get_opts(), (int)uVar7 < (int)(uint)*(byte *)(iVar5 + 0xd);
      uVar7 = uVar7 + 1) {
    iVar5 = *(int *)(_p_llm_env + 8) + uVar7 * 0x44;
    if ((*(char *)(iVar5 + 0x40) == '\t') && (*(char *)(iVar5 + 0x28) == '\0')) {
      r_ke_msg_send_basic(2,(uVar7 & 0xff) << 8 | 1,0);
      bVar1 = true;
    }
    if (*(char *)(*(int *)(_p_llm_env + 8) + uVar7 * 0x44 + 0x40) == '\f') {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar5 + 0x18) == '\0') {
        r_assert_err(0,"llm.c",0x50f);
      }
      r_lld_per_adv_ch_map_update(uVar7 & 0xff,iVar13);
    }
  }
  if (bVar1) {
    r_ke_timer_set(4,0,(uint)_r_lld_white_list_add_hack * 100);
    return;
  }
  *(undefined1 *)(_p_llm_env + 0x22) = 0;
  return;
}

