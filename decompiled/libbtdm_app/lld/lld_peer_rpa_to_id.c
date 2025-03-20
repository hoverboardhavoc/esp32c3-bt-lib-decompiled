/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  
  iVar1 = 0;
  if ((((param_2 != (byte *)0x0) && (param_1 != (void *)0x0)) && (*param_2 == 1)) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    uVar3 = 0;
    do {
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(short *)(iVar2 + uVar3 * 0x34) < 0) &&
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
  return iVar1;
}

