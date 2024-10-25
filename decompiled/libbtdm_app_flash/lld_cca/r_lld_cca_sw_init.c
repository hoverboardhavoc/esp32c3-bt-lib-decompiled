/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_sw_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_sw_init(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  puVar1 = p_lld_cca;
  if ((*(byte *)((int)p_lld_cca + 6) & 1) == 0) {
    *(byte *)((int)p_lld_cca + 6) = *(byte *)((int)p_lld_cca + 6) | 1;
    *puVar1 = r_lld_cca_evt_cbk;
    uVar3 = r_llm_master_ch_map_get();
    puVar2 = p_lld_cca;
    puVar1[7] = uVar3;
    pbVar5 = (byte *)puVar2[10];
    pbVar6 = pbVar5;
    do {
      pbVar7 = pbVar6 + 0xc;
      *pbVar6 = *pbVar6 | 1;
      pbVar6 = pbVar7;
    } while (pbVar7 != pbVar5 + 0x1e0);
    *(undefined2 *)((int)puVar2 + 0x12) = 0x640;
    iVar4 = r_sdk_config_get_opts_ext();
    r_lld_cca_config_init(0xc,*(undefined1 *)(iVar4 + 0x12),3,0,0);
    _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff;
    r_cca_hw_intr_set(1);
    bt_bb_tx_cca_set(1,0,0,0,0,0,0,0);
    r_btdm_config_cca_sw(0,0,0);
    return;
  }
  return;
}

