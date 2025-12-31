/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew_instant_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_instant_cbk(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = _lld_rpa_renew_env;
  if (_lld_rpa_renew_env != 0) {
    r_ble_log_internal_x1(0x202800b1,*(undefined4 *)(_lld_rpa_renew_env + 4));
    iVar5 = 0;
    do {
      iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
      if (*(short *)(iVar6 + iVar5) < 0) {
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar1 = *(ushort *)(iVar6 + iVar5);
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar2 = *(ushort *)(iVar6 + iVar5);
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar3 = *(ushort *)(iVar6 + iVar5);
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        *(ushort *)(iVar6 + iVar5) = (ushort)((uVar1 & 0x20) << 1) | uVar3 & 0xffbf;
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        uVar1 = *(ushort *)(iVar6 + iVar5);
        iVar6 = r_emi_get_mem_addr_by_offset(0xc60);
        *(ushort *)(iVar6 + iVar5) = (ushort)((uVar2 & 2) << 1) | uVar1 & 0xfffb;
      }
      iVar5 = iVar5 + 0x34;
    } while (iVar5 != 0x208);
    r_sch_arb_remove(iVar4,1);
    r_ke_free(_lld_rpa_renew_env);
    _lld_rpa_renew_env = 0;
    return;
  }
  r_assert_err(0,"lld.c",0x46d);
  return;
}

