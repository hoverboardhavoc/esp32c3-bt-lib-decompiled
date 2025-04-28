/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind_hack(uint param_1)

{
  uint uVar1;
  int iVar2;
  void *__src;
  undefined4 uVar3;
  undefined1 auStack_44 [12];
  uint uStack_38;
  
  uVar1 = (uint)*(byte *)(_p_lld_env + 0xd8);
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 4) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
    r_ble_log_internal_x1(0x40a00014,uVar1 << 8 | param_1);
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0x1000);
  __src = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(uVar1 * 0x14 + 0x12 + iVar2));
  memcpy(auStack_44,__src,0x22);
  iVar2 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar2 + 0x28) & 4) != 0) &&
     (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 2)) {
    r_ble_log_internal_hex(0x20a00015,0x22,auStack_44);
  }
  if ((uStack_38 & 0xffff) == uStack_38 >> 0x10) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar2 + 0x28) & 4) != 0) &&
       (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x40a00018,uVar1 << 8 | param_1,uStack_38);
    }
  }
  else {
    iVar2 = r_sdk_config_get_opts_ext();
    if ((*(char *)(iVar2 + 0x24) == '\0') ||
       (iVar2 = r_lld_adv_utils_verify_aa(uStack_38), iVar2 != 0)) {
      uVar3 = r_lld_adv_pkt_rx_connect_ind(param_1);
      return uVar3;
    }
    iVar2 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar2 + 0x28) & 4) != 0) &&
       (iVar2 = r_sdk_config_get_opts_ext(), *(byte *)(iVar2 + 0x2c) < 3)) {
      r_ble_log_internal_x2(0x40a00018,uVar1 << 8 | param_1,uStack_38);
      return 0;
    }
  }
  return 0;
}

