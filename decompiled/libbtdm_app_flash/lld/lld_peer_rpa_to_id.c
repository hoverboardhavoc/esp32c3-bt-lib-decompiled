/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld.o -> lld_peer_rpa_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int lld_peer_rpa_to_id(void *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  void *__src;
  uint uVar3;
  
  iVar1 = 0;
  if ((((param_2 != (byte *)0x0) && (param_1 != (void *)0x0)) && (*param_2 == 1)) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    uVar3 = 0;
    do {
      iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
      if ((*(short *)(iVar2 + uVar3 * 0x34) < 0) &&
         (iVar1 = lld_peer_rpa_res(param_1,uVar3 & 0xff), iVar1 != 0)) {
        iVar2 = r_emi_get_mem_addr_by_offset(0xc60);
        *param_2 = (byte)*(undefined2 *)(iVar2 + uVar3 * 0x34) & 1;
        __src = (void *)r_emi_get_mem_addr_by_offset((uVar3 & 0xff) * 0x34 + 0xc78);
        memcpy(param_1,__src,6);
        return iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 10);
  }
  return iVar1;
}

