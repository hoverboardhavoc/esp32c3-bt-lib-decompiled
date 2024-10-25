/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_tx_cal_con_timestamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_init_process_pkt_tx_cal_con_timestamp(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = _lld_init_env;
  bVar1 = (&co_rate_to_phy)[*(byte *)(_lld_init_env + 0x4e)];
  bVar2 = *(byte *)(*(int *)(param_1 * 4 + _lld_init_env) + 0x52);
  iVar6 = r_emi_get_mem_addr_by_offset(0x400);
  iVar5 = *(int *)(iVar4 + 0x54);
  uVar8 = (uint)*(ushort *)(iVar6 + (uint)bVar2 * 0x5a + 0x44) * 4;
  if (sdk_cfg_priv_opts == '\0') {
    iVar4 = iVar4 + (uint)bVar1 * 10;
    uVar3 = *(ushort *)(iVar4 + 4);
    uVar7 = (uint)*(ushort *)(iVar4 + 2) * 4;
    if (*(ushort *)(iVar4 + 2) == 0) {
      r_assert_err(0,"lld_init.c",0x94);
    }
    uVar7 = (uVar7 + iVar5) - (iVar5 + (uint)uVar3 * -2 & 0xfffffff) % uVar7 & 0xfffffff;
    if (uVar8 <= (uVar7 - iVar5 & 0xfffffff)) {
      return uVar7;
    }
    uVar7 = uVar7 + (uint)*(ushort *)(iVar4 + 2) * 4;
  }
  else {
    iVar6 = 1;
    if (*(char *)(iVar4 + 0x59) != '\0') {
      iVar6 = (1 < *(byte *)(iVar4 + 0x4e)) + 2;
    }
    uVar7 = iVar6 * 4 + iVar5 + uVar8;
  }
  return uVar7 & 0xfffffff;
}

