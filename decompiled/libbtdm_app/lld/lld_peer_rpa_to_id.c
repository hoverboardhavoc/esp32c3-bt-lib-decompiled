/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> lld.o -> lld_peer_rpa_to_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lld_peer_rpa_to_id(void *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  void *__src;
  uint uVar3;
  
  if ((((param_2 != (byte *)0x0) && (param_1 != (void *)0x0)) && (*param_2 == 1)) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    uVar3 = 0;
    do {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(short *)(iVar1 + uVar3 * 0x34) < 0) &&
         (iVar1 = lld_peer_rpa_res(param_1,uVar3 & 0xff), iVar1 != 0)) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        *param_2 = (byte)*(undefined2 *)(iVar2 + uVar3 * 0x34) & 1;
        __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                  ((uVar3 & 0xff) * 0x34 + 0xc78,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(param_1,__src,6);
        return iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 10);
  }
  return 0;
}

