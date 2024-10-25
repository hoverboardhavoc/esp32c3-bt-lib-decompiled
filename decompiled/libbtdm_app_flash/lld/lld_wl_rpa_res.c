/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> lld_wl_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int lld_wl_rpa_res(void *param_1,byte *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *__src;
  uint uVar3;
  int *piVar4;
  
  if ((((param_2 != (byte *)0x0) && (param_1 != (void *)0x0)) && (*param_2 != 0)) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    uVar3 = 0;
    do {
      iVar1 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((*(short *)(iVar1 + uVar3 * 0x34) < 0) &&
         (iVar1 = lld_peer_rpa_res(param_1,uVar3 & 0xff), iVar1 != 0)) {
        iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
        *param_2 = (byte)*(undefined2 *)(iVar2 + uVar3 * 0x34) & 1;
        __src = (void *)r_emi_get_mem_addr_by_offset((uVar3 & 0xff) * 0x34 + 0xc78);
        goto _L219;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 10);
    if (param_3 == 0) {
      piVar4 = &lld_wl_res_list;
      iVar2 = 0;
      do {
        if ((*piVar4 != 0) && (iVar1 = lld_rpa_res(*piVar4 + 7,param_1), iVar1 != 0)) {
          *param_2 = *(byte *)(&lld_wl_res_list)[iVar2];
          __src = (void *)((&lld_wl_res_list)[iVar2] + 1);
_L219:
          memcpy(param_1,__src,6);
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 != 0xc);
    }
  }
  return 0;
}

